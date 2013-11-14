#XEML-Lab 1.0



## Introduction   
===========
here is the documentation on classes and code architecture. You also found a short tutorial on how to use Xeml lab Software.



##Sources 
=======

 Sources are divided into Ontologies  and Graphic interface related classes. All components of Xeml format ( i.e. all tags in the Xml based document) are located in Ontologies folder while all graphical component are in  Xeml Designer folder.

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
		experiment time will be further translate into numbers of days in the xeml document.
	
* Add sub stories (split story) to the header story for different experimental conditions (you can set the time point by dragging the split story to the correct time position).

* Add Observation points to the given time point (you can set the time point by dragging the observation point icon to the correct time position).

* Describe your ObservationPoint by adding observations (samples). A wizard helps users to document observationPoint. 

***
using Wizard ObservationPoint
***
    
    1. first, you have to add a genotype (germ plasm) to your header story (all genotypes are inherited by child stories).

    2. Launch the wizard by clicking on add samples button.
    
    3. select your genotype and validate.
    
    4. add developmental stage ontology for your sample.
    
    5. select duration for observation, numbers of individuals sampled, the type of observation  (i.e destructive or non destructive observation) and validate.
    
    6. Specify structural and positioning (e.g. height From ground etc..) conditions used for these samples by choosing terms in ontologies trees (structure and positioning ontology).
    
    7. Click on finish to validate this observation Point.
    
***

* Add environmental variables or parameter (i.e  Temperature, light, substrate conditions, etc…).

***
adding environmental terms to a story
***
	 
	 1. first, select a story to defined and choose a term in the ontologies trees and click on addParameter button. 
	 
	 2. choose the timepoint for the term value set (i.e you can add multiples valueset if your parameter value changed during the experiment).
	 
	 3. you have to describe related contexts to this terms (i.e quantitative, qualitative and freetext context).
	 
	 4. add the term to the story by click on finish.
	 
***
importing sensor recorded environmental data using CSVLoader Wizard
***

	1. first, click on open a csv file in edit menu.

	2. when Wizard is opened, choose a csv file to load.

	3. select CSV columns headers you want to upload in your document.

	4. for each headers kept, choose the ontology related term and the related story in which you want to add this terms, then validate by clicking on finish.

*** 



* Add events to describe any actions performed during the experiment.

* you can visualize the Xeml document at any time of the description by clicking on code editor in Tools menu. 

 

 



