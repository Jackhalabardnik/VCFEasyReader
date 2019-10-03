##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=VCFEasyReaderTest
ConfigurationName      :=Release
WorkspacePath          :=/home/jacek/CLP/VCFEasyReader
ProjectPath            :=/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
<<<<<<< HEAD
User                   :=jacek
Date                   :=01/10/19
=======
User                   :=Jacek Wójcik
Date                   :=30/09/19
>>>>>>> b7b4f2337794784c4b81599a8b1ef44c6d92239e
CodeLitePath           :=/home/jacek/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="VCFEasyReaderTest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/home/jacek/CLP/VCFEasyReader/VCFEasyReader 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -O2 -std=c++14 -Wall $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) $(IntermediateDirectory)/TreeViewTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/ParserTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/ExporterTest.cpp$(ObjectSuffix) 



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
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix): CatchMain.cpp $(IntermediateDirectory)/CatchMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/CatchMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CatchMain.cpp$(DependSuffix): CatchMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CatchMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CatchMain.cpp$(DependSuffix) -MM CatchMain.cpp

$(IntermediateDirectory)/CatchMain.cpp$(PreprocessSuffix): CatchMain.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CatchMain.cpp$(PreprocessSuffix) CatchMain.cpp

$(IntermediateDirectory)/TreeViewTest.cpp$(ObjectSuffix): TreeViewTest.cpp $(IntermediateDirectory)/TreeViewTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/TreeViewTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TreeViewTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TreeViewTest.cpp$(DependSuffix): TreeViewTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TreeViewTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TreeViewTest.cpp$(DependSuffix) -MM TreeViewTest.cpp

$(IntermediateDirectory)/TreeViewTest.cpp$(PreprocessSuffix): TreeViewTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TreeViewTest.cpp$(PreprocessSuffix) TreeViewTest.cpp

$(IntermediateDirectory)/ParserTest.cpp$(ObjectSuffix): ParserTest.cpp $(IntermediateDirectory)/ParserTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/ParserTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ParserTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ParserTest.cpp$(DependSuffix): ParserTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ParserTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ParserTest.cpp$(DependSuffix) -MM ParserTest.cpp

$(IntermediateDirectory)/ParserTest.cpp$(PreprocessSuffix): ParserTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ParserTest.cpp$(PreprocessSuffix) ParserTest.cpp

$(IntermediateDirectory)/ExporterTest.cpp$(ObjectSuffix): ExporterTest.cpp $(IntermediateDirectory)/ExporterTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReaderTest/ExporterTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ExporterTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ExporterTest.cpp$(DependSuffix): ExporterTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ExporterTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ExporterTest.cpp$(DependSuffix) -MM ExporterTest.cpp

$(IntermediateDirectory)/ExporterTest.cpp$(PreprocessSuffix): ExporterTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ExporterTest.cpp$(PreprocessSuffix) ExporterTest.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


