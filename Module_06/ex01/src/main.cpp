#include "../include/Serializer.hpp"
#include "../include/colors.hpp"

void announcementTitle(std::string &message) {
    std::cout << "\n" << NEON_BLUE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_YELLOW << message << RESET << std::endl;
    std::cout << NEON_BLUE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

void announcementMessage(const std::string &message) {
    std::cout << "\n" << NEON_PURPLE << std::setfill('-') << std::setw(message.length() + 3) << RESET << std::endl;
    std::cout << NEON_GREEN << message << RESET << std::endl;
    std::cout << NEON_PURPLE << std::setfill('-') << std::setw(message.length()) << "\n" << RESET << std::endl;
}

int main() {

    {
        std::string title = "✅ Serialization and Deserialization Successful ✅";
        announcementTitle(title);
        Data data;
        data.content = "Too too roo !";

        std::string message = "Serializing data and storing the serialized address.";
        announcementMessage(message);

        uintptr_t serializedData = Serializer::serialize(&data);

        std::string message2 = "Deserializing the stored address back to data.";
        announcementMessage(message2);

        Data *deserializedData = Serializer::deserialize(serializedData);

        std::string message3 = "Comparing original and deserialized addresses.";
        announcementMessage(message3);

        std::cout << CYAN << "Original data address: (" << &data << ")" << RESET << std::endl;
        std::cout << CYAN << "Deserialized data address: (" << deserializedData << ")" << RESET << std::endl;

        if ((&data != deserializedData) || (data.content != deserializedData->content)) {
            std::cerr << NEON_RED << "Error: Address or content mismatch.\n"
                      << "Original address: " << &data << ", Deserialized address: " << deserializedData << "\n"
                      << "Original content: " << data.content << ", Deserialized content: " << deserializedData->content
                      << RESET << std::endl;
        } else {
            std::cout << NEON_GREEN << "Success: Addresses and content match.\n"
                      << "Original address: " << &data << ", Deserialized address: " << deserializedData << "\n"
                      << "Original content: " << data.content << ", Deserialized content: " << deserializedData->content
                      << RESET << std::endl;
        }
    }
    {
        std::string title = "❌ Serialization and Deserialization Failed ❌";
        announcementTitle(title);

        Data data;
        data.content = "Too too roo !";

        Data data2;
        data.content = "Hello !";

        std::string message = "Serializing data and storing the serialized address.";
        announcementMessage(message);

        uintptr_t serializedData = Serializer::serialize(&data2);

        std::string message2 = "Deserializing the stored address back to data.";
        announcementMessage(message2);

        Data *deserializedData = Serializer::deserialize(serializedData);

        std::string message3 = "Comparing original and deserialized addresses.";
        announcementMessage(message3);

        std::cout << CYAN << "Original data address: (" << &data << ")" << RESET << std::endl;
        std::cout << CYAN << "Deserialized data address: (" << deserializedData << ")" << RESET << std::endl;

        if ((&data != deserializedData) || (data.content != deserializedData->content)) {
            std::cerr << NEON_RED << "Error: Address or content mismatch.\n"
                      << "Original address: " << &data << ", Deserialized address: " << deserializedData << "\n"
                      << "Original content: " << data.content << ", Deserialized content: " << deserializedData->content
                      << RESET << std::endl;
        } else {
            std::cout << NEON_GREEN << "Success: Addresses and content match.\n"
                      << "Original address: " << &data << ", Deserialized address: " << deserializedData << "\n"
                      << "Original content: " << data.content << ", Deserialized content: " << deserializedData->content
                      << RESET << std::endl;
        }
    }
}