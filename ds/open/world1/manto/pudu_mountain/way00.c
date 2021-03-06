#include <ansi.h>

string *mountain_msg = ({
"此地處於深山絕嶺，仰觀崇嶺上的古松，在雲霧間似隱似現\n"
"，彷彿是絕頂仙人的居所，令人望之生敬。" ,
"以輕功\躍上陡峭的山壁後，漸漸地接近高處的庭樓，幾片白\n"
"雲飄了過來，將人包覆在一片白茫之中，更是有騰雲駕霧的感覺。" ,
"攀到了此處，山壁中間凹進一行棧道。沿著棧道走上山，走\n"
"了莫約十里路，只見道路越接近山頂，越是狹窄，路面也越是坎\n"
"坷不平。" ,
});

string *outdoor = ({
HIY"\n    山風逐漸大了起來，呼呼的吹著，松針如鋼針般打在行人臉上。\n"NOR,
MAG"\n    風沒有一點停的意思，不由得讓人更謹慎的在棧道中行走。\n"NOR,
WHT"\n    灰濛濛的雲層，如圍巾般將山頭輕輕的包著。\n"NOR,
CYN"\n    天上飄著如絮的雲朵，與地上景色互相呼應。\n"NOR,
HIC"\n    山間小雨正淅瀝瀝地下著。\n"NOR,
HIC"\n    風小些了，空氣中透著冰冷的氣息。\n"NOR,
});

string print_mountain_msg() 
{ 
    return mountain_msg[random(sizeof(mountain_msg))] + outdoor[random(sizeof(outdoor))];
}

