inherit ITEM;
void create()
{
        set_name("絹布", ({ "silk shawl","shawl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一條質地不錯的絲娟，上頭繡著一對鴛鴦，且在旁寫了數行字。\n");
                set("unit", "個");
           set("value",100);
        }
     setup();
}
