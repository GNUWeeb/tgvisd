
/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com> https://www.facebook.com/ammarfaizi2
 * @license GPL-v3
 * @package TeaBot
 */

#include <TeaBot/Responses/MyMessage.hpp>

namespace TeaBot::Responses {

/**
 * @param std::shared_ptr<Response> res
 */
MyMessage::MyMessage(std::shared_ptr<Response> res):
    res_(res)
{
}

/**
 * @return void
 */
void MyMessage::run()
{

}

} /* namespace TeaBot::Responses */