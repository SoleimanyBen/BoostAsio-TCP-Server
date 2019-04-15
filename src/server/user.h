
class User
{
public:
	User();

	void check_if_exists();

private:
	int user_id;
	int current_channel;

	std::string username;
};