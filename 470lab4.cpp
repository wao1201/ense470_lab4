// ense470 lab4: osg test

// description: a simple program that allow user to load osg models as they wish

#include <osgViewer/Viewer>
#include <osg/Group>
#include <osgDB/ReadFile> 
#include <iostream>

int main(){
	// create group node
	osg::ref_ptr<osg::Group> rootNode = new osg::Group;

	// read model files
	osg::ref_ptr<osg::Node> model1 = osgDB::readNodeFile("cow.osg");
	osg::ref_ptr<osg::Node> model2 = osgDB::readNodeFile("avatar.osg");
	osg::ref_ptr<osg::Node> model3 = osgDB::readNodeFile("cessnafire.osg");
	
	// ask user to choose one model to load
	int modelNum;
	cout<<"Please choose a model to load by entering number (1, 2,or 3): ";
	cin>>modelNum;
	
	// based on user choice, load model
	if(modelNum==1)
		rootNode->addChild(model1.get());
	else if(modelNum==2)
		rootNode->addChild(model2.get());
	else if(modelNum==3)
		rootNode->addChild(model3.get());

	// pass the root to viewer
	osgViewer::Viewer viewer;
	viewer.setSceneData( rootNode.get());
	viewer.setUpViewInWindow(50,50,800,600); // instead of full screen, set a window
	viewer.run();

}
