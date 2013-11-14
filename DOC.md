#XEML-Lab 1.0



## Introduction   
===========
here is the documentation on classes and code architecture. You also found a short tutorial on how to use Xeml lab Software.



##Sources 
=======

*  Sources are divided into Ontologies  and Graphic interface related classes. All components of Xeml format ( i.e. all tags in the Xml based document) are located in Ontologies folder while all graphical component are in  Xeml Designer folder.

##Developers Notes
==============

*  Clone from github (you have to be granted access to this git repository):
    hg clone https://github.com/cbib/XEML-Lab.git

*  Open XemlLab.pro files with QtCreator 2.6 or 

## Quick tutorial
============
When starting Xeml Lab Designer, one story is defined as header story (initial condition).
you can  :
	* Describe Experiment in term of experiment Time ( start date and end date for the header story ) 
		experiment time will be further translate into numbers of days in the xeml document.
	
	* Add sub stories (split story) to the header story for different experimental conditions (you can set the time point of the split by dragging the split story to the correct time position).

	* Add Observation points to the given time point (you can set the time point of an observation point by dragging the o.p icon to the correct time position).

	* Describe your ObservationPoint by adding observations (samples). A wizard helps users document his observationPoint. 
	** first, you have to add a genotype (germ plasm) to your header story ( all genotypes are inherited by child stories) 
	** then launch the wizard by clicking on add samples button.
	 
 



