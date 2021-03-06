/** 
    
    This file is part of Critter.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
*/

#include "CritterStable.h"
#include "CritterBodyDescription.h"

                                                                                       

namespace Critter
{

                                                                                       

BodyDescription::BodyDescription()
{
 reset();
}

BodyDescription::~BodyDescription()
{
 // Nothing to do in here.
}

void BodyDescription::reset()
{

 // Reset the physics bits.
 RigidBodyDescription::reset();

 // Reset the visual bits.
 mNode = 0;
 mSceneNodeDestructorBehaviour = Enums::SceneNodeDestructorBehaviour_Destroy;
 mRenderPriority = NxOgre::Enums::Priority_Medium;

}

bool BodyDescription::valid()
{

 // Check to see if the physics bits are valid or not.
 if (!RigidBodyDescription::valid())
  return false;

 // If there is an entity; there must be a node.
 if (mNode == 0)
  return false;
 
 // SceneNodeDestructorBehaviour can't be inherit.
 if (mSceneNodeDestructorBehaviour == Enums::SceneNodeDestructorBehaviour_Inherit)
  return false;
 
 // If we reached here then everything is okay.
 return true;
}

                                                                                       

}

                                                                                       

