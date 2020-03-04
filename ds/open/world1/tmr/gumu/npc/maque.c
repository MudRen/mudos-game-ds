// maque.c

inherit NPC;

void create()
{
        set_name("麻雀", ({ "maque bird", "bird"}));
        set("race", "野獸");
        set("age", 3);
        set("long", "一只小麻雀，在石室里飛上飛下。\n");
        set("attitude", "peaceful");

        set("chat_chance", 10);
        set("chat_msg", ({
                "麻雀唧唧喳喳叫了幾聲。\n",
                "麻雀撲騰著翅膀。\n",
                "麻雀一下撞到�暀W，“碰”地一聲又掉在地上。\n",
        }) );

        setup();
}

