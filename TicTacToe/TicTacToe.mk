##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TicTacToe
ConfigurationName      :=Debug
WorkspacePath          := "/home/zerokullneo/github/codelite/IArtificial"
ProjectPath            := "/home/zerokullneo/github/codelite/IArtificial/TicTacToe"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jose M Barba Gonzalez
Date                   :=23/02/16
CodeLitePath           :="/home/zerokullneo/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TicTacToe.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/minimaxAlum.c$(ObjectSuffix) $(IntermediateDirectory)/podaAB.c$(ObjectSuffix) $(IntermediateDirectory)/tictactoe.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/zerokullneo/github/codelite/IArtificial/TicTacToe/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/minimaxAlum.c$(ObjectSuffix): minimaxAlum.c $(IntermediateDirectory)/minimaxAlum.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/zerokullneo/github/codelite/IArtificial/TicTacToe/minimaxAlum.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/minimaxAlum.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/minimaxAlum.c$(DependSuffix): minimaxAlum.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/minimaxAlum.c$(ObjectSuffix) -MF$(IntermediateDirectory)/minimaxAlum.c$(DependSuffix) -MM "minimaxAlum.c"

$(IntermediateDirectory)/minimaxAlum.c$(PreprocessSuffix): minimaxAlum.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/minimaxAlum.c$(PreprocessSuffix) "minimaxAlum.c"

$(IntermediateDirectory)/podaAB.c$(ObjectSuffix): podaAB.c $(IntermediateDirectory)/podaAB.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/zerokullneo/github/codelite/IArtificial/TicTacToe/podaAB.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/podaAB.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/podaAB.c$(DependSuffix): podaAB.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/podaAB.c$(ObjectSuffix) -MF$(IntermediateDirectory)/podaAB.c$(DependSuffix) -MM "podaAB.c"

$(IntermediateDirectory)/podaAB.c$(PreprocessSuffix): podaAB.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/podaAB.c$(PreprocessSuffix) "podaAB.c"

$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix): tictactoe.c $(IntermediateDirectory)/tictactoe.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/zerokullneo/github/codelite/IArtificial/TicTacToe/tictactoe.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tictactoe.c$(DependSuffix): tictactoe.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tictactoe.c$(ObjectSuffix) -MF$(IntermediateDirectory)/tictactoe.c$(DependSuffix) -MM "tictactoe.c"

$(IntermediateDirectory)/tictactoe.c$(PreprocessSuffix): tictactoe.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tictactoe.c$(PreprocessSuffix) "tictactoe.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


