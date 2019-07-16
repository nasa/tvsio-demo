#!/usr/bin/python

import os, shutil, re, sys

###############################################################################
### This script does some odds and ends work for integrating aso_cfs mission 
### build into habulous.
###############################################################################

##  - Remove the CFE_MAKE_BIG16 macro as it is not needed for our version of SCH
##  - Replace CCSDS header portion of entry to field-based entry
##  - Make sure references to sch app name is 'SCH' not 'sch'

def process_sch_def_msgtbl_file(oFile, iFile):
  ifp = open(iFile, 'r')
  ofp = open(oFile, 'w')

  inSwapDefineBlock = False
  includedCCDD = False
  addedCounterTelemMID = -1
  addedCounterWakeMID = -1
  entryIdx = -1
  numCurlies = 0
  for line in ifp:

     numCurlies += line.count('{')
     if numCurlies == 3:
        entryIdx += 1

     # Filter out macro definition
     if line.startswith('#if ENDIAN'):
        inSwapDefineBlock = True

     if inSwapDefineBlock:
        if line.startswith('#endif'):
           inSwapDefineBlock = False
     else:
        # Parse and remove CFE_MAKE_BIG16 macro calls
        remLine = line
        lineToWrite = ""
        while remLine:
           part = remLine.partition('CFE_MAKE_BIG16')
           lineToWrite += part[0]
           after = part[2].partition('(')[2]
           ss = after.partition(')')
           val = ss[0]
           lineToWrite += val
           remLine = ss[2]

        remLine = lineToWrite
        part = remLine.rpartition('{')
        if not part[0]:
           ofp.write(lineToWrite)
           continue
        lineToWrite = part[0][:-1]
        part = part[2].partition('}')
        middle = part[0]
        after = part[2][1:]
        spl = middle.split(',')
        lineToWrite += spl[0] + ","
        valIdx = len(spl)
        for idx in range(len(spl)-1,0,-1):
           if '0x0000' in spl[idx]:
              valIdx = idx
           else:
             break
        if valIdx >= 4:
           if valIdx <= 6:
              lineToWrite += " 0, {"
           else:
              lineToWrite += " " + str(2*(valIdx-6)) + ", {"
        for idx in range(3,len(spl)):
           if idx == valIdx:
              break
           lineToWrite += spl[idx] + ","
        lineToWrite = lineToWrite[:-1]
        if lineToWrite[-1] != ' ':
           lineToWrite += ' '
        if valIdx >= 4:
           lineToWrite += "} "
        lineToWrite += after

        ofp.write(lineToWrite)


     numCurlies -= line.count('}')


  return (addedCounterTelemMID, addedCounterWakeMID)


process_sch_def_msgtbl_file(sys.argv[2], sys.argv[1])
