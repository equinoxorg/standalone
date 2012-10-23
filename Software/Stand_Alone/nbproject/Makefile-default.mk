#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/buzz.p1 ${OBJECTDIR}/config_bits.p1 ${OBJECTDIR}/keypad.p1 ${OBJECTDIR}/lcd.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/eeprom.p1 ${OBJECTDIR}/i2c.p1 ${OBJECTDIR}/rtc.p1 ${OBJECTDIR}/unlock_codes.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/buzz.p1.d ${OBJECTDIR}/config_bits.p1.d ${OBJECTDIR}/keypad.p1.d ${OBJECTDIR}/lcd.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/eeprom.p1.d ${OBJECTDIR}/i2c.p1.d ${OBJECTDIR}/rtc.p1.d ${OBJECTDIR}/unlock_codes.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/buzz.p1 ${OBJECTDIR}/config_bits.p1 ${OBJECTDIR}/keypad.p1 ${OBJECTDIR}/lcd.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/eeprom.p1 ${OBJECTDIR}/i2c.p1 ${OBJECTDIR}/rtc.p1 ${OBJECTDIR}/unlock_codes.p1


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K22
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/buzz.p1: buzz.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 buzz.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  buzz.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/buzz.p1: > ${OBJECTDIR}/buzz.p1.d
	@cat ${OBJECTDIR}/buzz.dep >> ${OBJECTDIR}/buzz.p1.d
	@${FIXDEPS} "${OBJECTDIR}/buzz.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/config_bits.p1: config_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 config_bits.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  config_bits.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/config_bits.p1: > ${OBJECTDIR}/config_bits.p1.d
	@cat ${OBJECTDIR}/config_bits.dep >> ${OBJECTDIR}/config_bits.p1.d
	@${FIXDEPS} "${OBJECTDIR}/config_bits.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/keypad.p1: keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 keypad.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  keypad.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/keypad.p1: > ${OBJECTDIR}/keypad.p1.d
	@cat ${OBJECTDIR}/keypad.dep >> ${OBJECTDIR}/keypad.p1.d
	@${FIXDEPS} "${OBJECTDIR}/keypad.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/lcd.p1: lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 lcd.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  lcd.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/lcd.p1: > ${OBJECTDIR}/lcd.p1.d
	@cat ${OBJECTDIR}/lcd.dep >> ${OBJECTDIR}/lcd.p1.d
	@${FIXDEPS} "${OBJECTDIR}/lcd.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 main.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  main.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/main.p1: > ${OBJECTDIR}/main.p1.d
	@cat ${OBJECTDIR}/main.dep >> ${OBJECTDIR}/main.p1.d
	@${FIXDEPS} "${OBJECTDIR}/main.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/eeprom.p1: eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 eeprom.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  eeprom.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/eeprom.p1: > ${OBJECTDIR}/eeprom.p1.d
	@cat ${OBJECTDIR}/eeprom.dep >> ${OBJECTDIR}/eeprom.p1.d
	@${FIXDEPS} "${OBJECTDIR}/eeprom.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/i2c.p1: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 i2c.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  i2c.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/i2c.p1: > ${OBJECTDIR}/i2c.p1.d
	@cat ${OBJECTDIR}/i2c.dep >> ${OBJECTDIR}/i2c.p1.d
	@${FIXDEPS} "${OBJECTDIR}/i2c.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/rtc.p1: rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 rtc.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  rtc.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/rtc.p1: > ${OBJECTDIR}/rtc.p1.d
	@cat ${OBJECTDIR}/rtc.dep >> ${OBJECTDIR}/rtc.p1.d
	@${FIXDEPS} "${OBJECTDIR}/rtc.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/unlock_codes.p1: unlock_codes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 unlock_codes.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  unlock_codes.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/unlock_codes.p1: > ${OBJECTDIR}/unlock_codes.p1.d
	@cat ${OBJECTDIR}/unlock_codes.dep >> ${OBJECTDIR}/unlock_codes.p1.d
	@${FIXDEPS} "${OBJECTDIR}/unlock_codes.p1.d" $(SILENT) -ht
	
else
${OBJECTDIR}/buzz.p1: buzz.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 buzz.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  buzz.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/buzz.p1: > ${OBJECTDIR}/buzz.p1.d
	@cat ${OBJECTDIR}/buzz.dep >> ${OBJECTDIR}/buzz.p1.d
	@${FIXDEPS} "${OBJECTDIR}/buzz.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/config_bits.p1: config_bits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 config_bits.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  config_bits.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/config_bits.p1: > ${OBJECTDIR}/config_bits.p1.d
	@cat ${OBJECTDIR}/config_bits.dep >> ${OBJECTDIR}/config_bits.p1.d
	@${FIXDEPS} "${OBJECTDIR}/config_bits.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/keypad.p1: keypad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 keypad.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  keypad.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/keypad.p1: > ${OBJECTDIR}/keypad.p1.d
	@cat ${OBJECTDIR}/keypad.dep >> ${OBJECTDIR}/keypad.p1.d
	@${FIXDEPS} "${OBJECTDIR}/keypad.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/lcd.p1: lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 lcd.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  lcd.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/lcd.p1: > ${OBJECTDIR}/lcd.p1.d
	@cat ${OBJECTDIR}/lcd.dep >> ${OBJECTDIR}/lcd.p1.d
	@${FIXDEPS} "${OBJECTDIR}/lcd.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 main.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  main.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/main.p1: > ${OBJECTDIR}/main.p1.d
	@cat ${OBJECTDIR}/main.dep >> ${OBJECTDIR}/main.p1.d
	@${FIXDEPS} "${OBJECTDIR}/main.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/eeprom.p1: eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 eeprom.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  eeprom.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/eeprom.p1: > ${OBJECTDIR}/eeprom.p1.d
	@cat ${OBJECTDIR}/eeprom.dep >> ${OBJECTDIR}/eeprom.p1.d
	@${FIXDEPS} "${OBJECTDIR}/eeprom.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/i2c.p1: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 i2c.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  i2c.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/i2c.p1: > ${OBJECTDIR}/i2c.p1.d
	@cat ${OBJECTDIR}/i2c.dep >> ${OBJECTDIR}/i2c.p1.d
	@${FIXDEPS} "${OBJECTDIR}/i2c.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/rtc.p1: rtc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 rtc.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  rtc.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/rtc.p1: > ${OBJECTDIR}/rtc.p1.d
	@cat ${OBJECTDIR}/rtc.dep >> ${OBJECTDIR}/rtc.p1.d
	@${FIXDEPS} "${OBJECTDIR}/rtc.p1.d" $(SILENT) -ht
	
${OBJECTDIR}/unlock_codes.p1: unlock_codes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	${MP_CC} --pass1 unlock_codes.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@${MP_CC} --scandep  unlock_codes.c $(MP_EXTRA_CC_PRE) -q --chip=$(MP_PROCESSOR_OPTION) -P  --outdir="${OBJECTDIR}" -N31 -I".." --warn=0 --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 --cp=16 -Blarge --double=24  --mode=lite -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s"  
	@echo ${OBJECTDIR}/unlock_codes.p1: > ${OBJECTDIR}/unlock_codes.p1.d
	@cat ${OBJECTDIR}/unlock_codes.dep >> ${OBJECTDIR}/unlock_codes.p1.d
	@${FIXDEPS} "${OBJECTDIR}/unlock_codes.p1.d" $(SILENT) -ht
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) -odist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  -mdist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.map --summary=default,-psect,-class,+mem,-hex --chip=$(MP_PROCESSOR_OPTION) -P --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -D__DEBUG --debugger=realice -N31 -I".." --warn=0 --cp=16 -Blarge --double=24  --mode=lite  --output=default,-inhx032 -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s" ${OBJECTFILES_QUOTED_IF_SPACED}    
	${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.hex
else
dist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) -odist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -mdist/${CND_CONF}/${IMAGE_TYPE}/Stand_Alone.${IMAGE_TYPE}.map --summary=default,-psect,-class,+mem,-hex --chip=$(MP_PROCESSOR_OPTION) -P --runtime=default,+clear,+init,-keep,-download,+stackwarn,-config,+clib,+plib --opt=all,+asm,-asmfile,-speed,+space,9 -N31 -I".." --warn=0 --cp=16 -Blarge --double=24  --mode=lite  --output=default,-inhx032 -g --asmlist "--errformat=%%f:%%l: error: %%s" "--msgformat=%%f:%%l: advisory: %%s" "--warnformat=%%f:%%l warning: %%s" ${OBJECTFILES_QUOTED_IF_SPACED}    
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
