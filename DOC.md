#XEML-Lab 1.0



## Introduction   
===========
here is the documentation on classes and code architecture. You also found a short tutorial on how to use Xeml lab Software.



##Sources 
=======

 Sources are divided into XemlCore classes and Graphical interface related classes. All components of Xeml format ( i.e. all tags in the Xml based document) are located in XemlCore/CoreObjects folder while all graphical component are in  Xeml Designer folder.
 
###Example Xeml file
=====================
 
 	<?xml version="1.0" encoding="utf-16"?>
	<xeml:XEMLDocument XemlVersion="1.1.0" xmlns:xeml="http://www.mpimp-golm.mpg.de/2009/XEML">
	<xeml:Resources>
    <xeml:EnvironmentalOntology NS="XEO" InstanceLocation="http://rest.bioontology.org/bioportal/ontologies/download/49450?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d" HandlerUri="http://xeml.mpimp-golm.mpg.de/xemlobo" />
    <xeml:EnvironmentalOntology NS="EO" InstanceLocation="http://rest.bioontology.org/bioportal/ontologies/download/45260?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d" HandlerUri="http://xeml.mpimp-golm.mpg.de/xemleo" />
    <xeml:EnvironmentalOntology NS="EnvO" InstanceLocation="http://rest.bioontology.org/bioportal/ontologies/download/47614?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d" HandlerUri="http://xeml.mpimp-golm.mpg.de/xemlenvo" />
    <xeml:OrganismStructureOntology NS="PO_Structure" InstanceLocation="http://rest.bioontology.org/bioportal/ontologies/download/47887?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d" HandlerUri="http://www.plantontology.org/PlantStructure" />
    <xeml:DevelopmentalOntology NS="PO_Development" InstanceLocation="http://rest.bioontology.org/bioportal/ontologies/download/47838?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d" HandlerUri="http://www.plantontology.org/DevelopmentalStage" />
    <xeml:PositioningOntology NS="XEO_Positioning" InstanceLocation="http://xeml.mpimp-golm.mpg.de/2007/XeO/PosO.xml" HandlerUri="http://www.mpimp-golm.mpg.de/2009/XEML/Positioning" />
  	</xeml:Resources>
	<xeml:Experiment Id="{f9632d75-2670-4e46-b1f5-b1279bc8707c}" Name="New experiment" ObservationTime="35.00:00:00" StartDate="2009-07-08T12:39:00">
		<xeml:Story Label="base line" />
	</xeml:Experiment>
</xeml:XEMLDocument>`.

##Developers Notes
==============

*  Clone from github (you have to be granted access to this git repository):
    hg clone https://github.com/cbib/XEML-Lab.git

*  Open XemlLab.pro files with QtCreator 2.6 or higher.
*  use qmake to build the makefile and run the application.

## Quick tutorial
============
When starting Xeml Lab Designer, one story is defined as header story (initial condition).
you can  :

* Describe Experiment in term of experiment Time ( start date and end date for the header story ) 
		experiment time will be further translate into numbers of days, hours, minutes and seconds in the xeml document.
	
* Add substories (split story) to the header story for different experimental conditions (you can set the time point by dragging the split story to the correct time position).

* Add Observation points to the given time point (you can set the time point by dragging the observation point icon to the correct time position).

* Describe your ObservationPoint by adding observations (samples). A wizard helps users to document observationPoint but you first need to describe a genotype related to your samples.(all genotypes are inherited by child stories).

***
How to use Wizard for Observation Point
***
            
    1. Launch the wizard by clicking on add samples button.
   	
    2. select your genotype by double clicking and validate.
    
    3. add developmental stage ontology term for your sample.
    
    4. select duration for observation, numbers of individuals sampled, the type of observation  (i.e destructive or non-destructive observation) and validate.
    
    5. Specify structural and positioning (e.g. height From ground etc..) conditions used for these samples by choosing terms in corresponding tree (structure and positioning ontology).
    
    6. Click on finish to validate this observation Point.
    
***

* Add environmental variables or parameter (i.e  Temperature, light, substrate conditions, etc…). each time you add a parameter, you need to define the timepoint at which this parameter have effects. 


<!--<img src="/Users/benjamindartigues/Desktop/parameter_edit.png" alt="Drawing" style="width: 600px;"/>-->
***
How to add environmental terms to a story
***
	 
	 1. first, select a story to defined and choose a term in the ontologies trees and click on addParameter button. 
	 
	 2. choose the timepoint for the term value set (i.e you can add multiples valueset if your parameter value changed during the experiment).
	 
	 3. you have to describe related contexts to this terms (i.e quantitative, qualitative and freetext context).
	 
	 4. add the term to the story by click on finish.
	 
***
how to import sensor recorded environmental data using CSVLoader Wizard
***

	1. first, click on open a csv file in edit menu.

	2. when Wizard is opened, choose a csv file to load.

	3. select CSV columns headers you want to upload in your document.

	4. for each headers kept, choose the ontology related term and the related story in which you want to add this terms, then validate by clicking on finish.

*** 



* Add events to describe any actions performed during the experiment.

* you can visualize the Xeml document at any time of the description by clicking on code editor in Tools menu. 

 

 



