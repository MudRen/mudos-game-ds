// daodejing-i.c

inherit ITEM;

void create()
{
        set_name( "道德經「上捲」", ({ "jing", "daode jing" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "這是一冊道德經「上捲」，由體道第一始至去用第四十止。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "taoism",       // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost": 20,        // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    50,     // the maximum level you can learn
                ]) );
        }
}
