#!/bin/bash

FREE_BLOCKS=$(vm_stat | grep free | awk '{ print $3 }' | sed 's/\.//')
INACTIVE_BLOCKS=$(vm_stat | grep inactive | awk '{ print $3 }' | sed 's/\.//')
SPECULATIVE_BLOCKS=$(vm_stat | grep speculative | awk '{ print $3 }' | sed 's/\.//')

FREE=$((($FREE_BLOCKS+SPECULATIVE_BLOCKS)*$(pagesize)/1048576))
INACTIVE=$(($INACTIVE_BLOCKS*$(pagesize)/1048576))
TOTAL=$((($FREE+$INACTIVE)))
echo Free:       $FREE MB
echo Inactive:   $INACTIVE MB
echo Total_free: $TOTAL MB