inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("���Q���氮", ({ "oreo cookies","oreo","cookies" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�@�]�¶ª����J�O�氮�A���J�O���������H�f�����y�C
LONG);
                set("unit","�]");
                set("value",500);
                set("eat_msg","$N�q�@�]���Q���氮���U�l�����X�䤤�@���A�T�]���`���Y�F�U�h�C\n");
                set("heal_hp",20);
                set("food_remaining",12);
        }
     setup();
}
