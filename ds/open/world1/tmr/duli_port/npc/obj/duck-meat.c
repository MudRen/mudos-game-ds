inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("烘烤全鴨", ({ "duck meat","meat","_OBJ_ID_DUCK_" }));
        if( !clonep() ) {
                set("unit", "個");
                set("base_weight", 500);
                set("food_stuff", 250);
                set("long", "一隻香噴噴的烤全鴨，陣陣的香味誘得你食指大動啊！！\n");
        }
          set("value",250);
        setup();
}

