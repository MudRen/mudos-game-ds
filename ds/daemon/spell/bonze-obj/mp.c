inherit ITEM;
inherit F_WATER;
void create()
{
    set_name("�k���", ({ "red wine","wine" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","�o�ذs�Q���O�ݶ��h�Q�A�b�X�îɷ|���X�Ӯb�л��Ȫ��A\n"
        "�ҥH�٤����u�k����v�C\n");
              set("unit", "�~");
          set("value", 180);    
          set("heal_mp",20);
          set("water_remaining", 3);
        }
        setup();
}


