inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�M�N���n", ({ "duck meat","meat","_OBJ_ID_DUCK_" }));
        if( !clonep() ) {
                set("unit", "��");
                set("base_weight", 500);
                set("food_stuff", 250);
                set("long", "�@�����Q�Q���N���n�A�}�}���������o�A�����j�ʰڡI�I\n");
        }
          set("value",250);
        setup();
}

