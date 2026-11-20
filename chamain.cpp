#include "crow.h"

int main()
{
    crow::SimpleApp app;

    // Simple test route for checking that the backend is running.
    CROW_ROUTE(app, "/api/message")([]() {
        crow::response response;
        response.code = 200;
        response.set_header("Content-Type", "application/json");
        response.set_header("Access-Control-Allow-Origin", "*");
        response.body = R"({"message":"CinNova backend is running."})";
        return response;
    });

    app.port(18080).multithreaded().run();

    return 0;
}
