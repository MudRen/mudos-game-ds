inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�J�����", ({ "egg moon cake","cake" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�Ӧb����`�~��R�o�쪺���@�A�o�ؤf�������_�A���k�O�C\n");
                set("unit", "��");
                set("value",500);
                set("heal_mp",50);
                set("food_remaining",2);
        }
     setup();
}

