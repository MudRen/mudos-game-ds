inherit ITEM;
inherit F_FOOD;


string* fish_name=({
        "����Ѫ��K ","�w��Ѫ��K ","�|�_��"
        "�T����","�㾦��","�u�k������","�s�u���䳽","�_����","���B��",
 });

void create()
{
        string n=fish_name[random(sizeof(fish_name))];
        set_name( n, ({ "fish" }) );
        if( !clonep() ) {
                  set("unit", "��");
                set("base_unit", "��");
                set("food_stuff", 50);
                set("long", 
                "�o�O�@���賨�W����"+ n +"�A�b�A��W�٬��۶ø����C\n"
                );
        }
        set("value", (1+random(5))*10);
          set_weight(500);
        setup();
}

