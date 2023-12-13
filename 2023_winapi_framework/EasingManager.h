#pragma once

#define PI 3.141592f

enum class Ease {


    InSine,
    OutSine,
    InOutSine,
    InQuad,
    OutQuad,
    InOutQuad,
    InCubic,
    OutCubic,
    InOutCubic,
    InQuart,
    OutQuart,
    InOutQuart,
    InQuint,
    OutQuint,
    InOutQuint,
    InExpo,
    OutExpo,
    InOutExpo,
    InCirc,
    OutCirc,
    InOutCirc,
    InElastic,
    OutElastic,
    InOutElastic,
    InBack,
    OutBack,
    InOutBack,
    InBounce,
    OutBounce,
    InOutBounce,

};

class EasingManager
{

    SINGLE(EasingManager);

private:
    const float c1 = 1.70158f;
    const float c2 = c1 * 1.525f;
    const float c3 = c1 + 1;
    const float c4 = (2 * PI) / 3;
    const float c5 = (2 * PI) / 4.5f;
    const float n1 = 7.5625f;
    const float d1 = 2.75f;

public:

    float Easing(float x, Ease ease) {

        switch (ease)
        {
        case Ease::InSine:

            return 1 - cosf((x * PI) / 2);

        case Ease::OutSine:

            return sinf((x * PI) / 2);

        case Ease::InOutSine:

            return -(cosf(PI * x) - 1) / 2;

        case Ease::InQuad:

            return x * x;

        case Ease::OutQuad:

            return 1 - (1 - x) * (1 - x);

        case Ease::InOutQuad:

            if (x < 0.5f) {

                return 2 * x * x;

            }
            else {

                return 1 - powf(-2 * x + 2, 2) / 2;

            }

            break;
        case Ease::InCubic:

            return x * x * x;

        case Ease::OutCubic:

            return 1 - powf(1 - x, 3);

        case Ease::InOutCubic:

            if (x < 0.5f) {

                return 4 * x * x * x;

            }
            else {

                return 1 - powf(-2 * x + 2, 3) / 2;
            }

        case Ease::InQuart:

            return x * x * x * x;

        case Ease::OutQuart:

            return 1 - powf(1 - x, 4);

        case Ease::InOutQuart:

            if (x < 0.5f) {

                return 8 * x * x * x * x;

            }
            else {

                return 1 - powf(-2 * x + 2, 4) / 2;

            }

        case Ease::InQuint:

            return x * x * x * x * x;

        case Ease::OutQuint:

            return 1 - powf(1 - x, 5);

        case Ease::InOutQuint:

            return x < 0.5f ? 16 * x * x * x * x * x : 1 - powf(-2 * x + 2, 5) / 2;

        case Ease::InExpo:

            return x == 0 ? 0 : powf(2, 10 * x - 10);

        case Ease::OutExpo:

            return x == 1 ? 1 : 1 - powf(2, -10 * x);

        case Ease::InOutExpo:

            return x == 0
                ? 0
                : x == 1
                ? 1
                : x < 0.5f ? powf(2, 20 * x - 10) / 2
                : (2 - powf(2, -20 * x + 10)) / 2;

        case Ease::InCirc:

            return 1 - sqrtf(1 - powf(x, 2));

        case Ease::OutCirc:

            return sqrtf(1 - powf(x - 1, 2));

        case Ease::InOutCirc:

            return x < 0.5f
                ? (1 - sqrtf(1 - powf(2 * x, 2))) / 2
                : (sqrtf(1 - powf(-2 * x + 2, 2)) + 1) / 2;

        case Ease::InElastic:

            return x == 0
                ? 0
                : x == 1
                ? 1
                : -powf(2, 10 * x - 10) * sinf((x * 10 - 10.75) * c4);

        case Ease::OutElastic:

            return x == 0
                ? 0
                : x == 1
                ? 1
                : powf(2, -10 * x) * sinf((x * 10 - 0.75) * c4) + 1;

        case Ease::InOutElastic:

            return x == 0
                ? 0
                : x == 1
                ? 1
                : x < 0.5f
                ? -(powf(2, 20 * x - 10) * sinf((20 * x - 11.125) * c5)) / 2
                : (powf(2, -20 * x + 10) * sinf((20 * x - 11.125) * c5)) / 2 + 1;

        case Ease::InBack:

            return c3 * x * x * x - c1 * x * x;

        case Ease::OutBack:

            return 1 + c3 * powf(x - 1, 3) + c1 * powf(x - 1, 2);

        case Ease::InOutBack:

            return x < 0.5f
                ? (powf(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
                : (powf(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;

        case Ease::InBounce:

            return 1 - Easing(1 - x, Ease::OutBounce);

        case Ease::OutBounce:

            if (x < 1 / d1) {
                return n1 * x * x;
            }
            else if (x < 2 / d1) {
                return n1 * (x -= 1.5f / d1) * x + 0.75f;
            }
            else if (x < 2.5f / d1) {
                return n1 * (x -= 2.25f / d1) * x + 0.9375f;
            }
            else {
                return n1 * (x -= 2.625f / d1) * x + 0.984375f;
            }

        case Ease::InOutBounce:

            return x < 0.5
                ? (1 - Easing(1 - 2 * x, Ease::OutBounce)) / 2
                : (1 + Easing(2 * x - 1, Ease::OutBounce)) / 2;

        default:
            return x;
        }

    }

    Vec2 EasingVec(Vec2 start, Vec2 end, float time, Ease ease) {

        return Lerp(start, end, Easing(time, ease));

    }

	Vec2 Lerp(Vec2 a, Vec2 b, float t) {

		return Vec2({ a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t });

	}

};

