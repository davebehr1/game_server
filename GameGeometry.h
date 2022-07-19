namespace PongGame
{
    class GameGeometry
    {
    public:
        GameGeometry() {}
        static const int GoalSize;
        static const float PaddleSpeed;
        static const Point PlayArea = new Point(8, 8);
        static const Vector2 ScreenCenter = new Vector2();
        static const Point BallSize;
    };
};