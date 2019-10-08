##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=VCFEasyReader
ConfigurationName      :=Release
WorkspacePath          :=/home/jacek/CLP/VCFEasyReader
ProjectPath            :=/home/jacek/CLP/VCFEasyReader/VCFEasyReader
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jacek Wójcik
Date                   :=08/10/19
CodeLitePath           :=/home/jacek/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="VCFEasyReader.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  $(shell pkg-config --libs gtkmm-3.0)
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -std=c++14 -Wall $(shell pkg-config --cflags gtkmm-3.0) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/TreeView.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainWindow.cpp$(ObjectSuffix) $(IntermediateDirectory)/Contact.cpp$(ObjectSuffix) $(IntermediateDirectory)/Parser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exporter.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReader/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/TreeView.cpp$(ObjectSuffix): TreeView.cpp $(IntermediateDirectory)/TreeView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReader/TreeView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TreeView.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TreeView.cpp$(DependSuffix): TreeView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TreeView.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TreeView.cpp$(DependSuffix) -MM TreeView.cpp

$(IntermediateDirectory)/TreeView.cpp$(PreprocessSuffix): TreeView.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TreeView.cpp$(PreprocessSuffix) TreeView.cpp

$(IntermediateDirectory)/MainWindow.cpp$(ObjectSuffix): MainWindow.cpp $(IntermediateDirectory)/MainWindow.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReader/MainWindow.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainWindow.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainWindow.cpp$(DependSuffix): MainWindow.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainWindow.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainWindow.cpp$(DependSuffix) -MM MainWindow.cpp

$(IntermediateDirectory)/MainWindow.cpp$(PreprocessSuffix): MainWindow.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainWindow.cpp$(PreprocessSuffix) MainWindow.cpp

$(IntermediateDirectory)/Contact.cpp$(ObjectSuffix): Contact.cpp $(IntermediateDirectory)/Contact.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReader/Contact.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Contact.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Contact.cpp$(DependSuffix): Contact.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Contact.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Contact.cpp$(DependSuffix) -MM Contact.cpp

$(IntermediateDirectory)/Contact.cpp$(PreprocessSuffix): Contact.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Contact.cpp$(PreprocessSuffix) Contact.cpp

$(IntermediateDirectory)/Parser.cpp$(ObjectSuffix): Parser.cpp $(IntermediateDirectory)/Parser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReader/Parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Parser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Parser.cpp$(DependSuffix): Parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Parser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Parser.cpp$(DependSuffix) -MM Parser.cpp

$(IntermediateDirectory)/Parser.cpp$(PreprocessSuffix): Parser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Parser.cpp$(PreprocessSuffix) Parser.cpp

$(IntermediateDirectory)/Exporter.cpp$(ObjectSuffix): Exporter.cpp $(IntermediateDirectory)/Exporter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jacek/CLP/VCFEasyReader/VCFEasyReader/Exporter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exporter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exporter.cpp$(DependSuffix): Exporter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exporter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exporter.cpp$(DependSuffix) -MM Exporter.cpp

$(IntermediateDirectory)/Exporter.cpp$(PreprocessSuffix): Exporter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exporter.cpp$(PreprocessSuffix) Exporter.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


