// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		bool notBanned{true};
		// TODO: Add your code here to build a collection of Profiles.
		//         The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.

        for (size_t i = 0; i < allProfiles.size(); ++i) {
            const Profile& currentProfile = allProfiles[i];

			for (size_t j = 0; j < bannedProfiles.size() && notBanned; j++)
				notBanned = &currentProfile != &bannedProfiles[i];

			if(notBanned)
			{
				auto* temp = new Profile(currentProfile);

				try
				{
					temp->validateAddress();
					result += temp;
				}
				catch (string& err)
				{
					delete temp;
					cerr << "Validation error: " << err << '\n';
				}
			}
        }

		return result;
	}
}
