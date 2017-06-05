#pragma once

namespace net {

	class Net_Chat
	{
	public:
		Net_Chat();
		void chat_menu();
		void start_server();
		void start_client();

		~Net_Chat();
	};
}
