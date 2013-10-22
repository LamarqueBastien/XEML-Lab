#ifndef COMPONENTLOADSTATE_H
#define COMPONENTLOADSTATE_H

namespace Xeml {

	namespace Document{

		typedef enum
			{
			Untouched,
			Loaded,
			Failed,
			UnknownComponent
			}ComponentLoadState;
	}
}


#endif // COMPONENTLOADSTATE_H
