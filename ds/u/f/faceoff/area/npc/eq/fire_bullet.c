inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("����",({"bullet"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�o�O���j�M�Ϊ��u��, ��˫��O: reload\n");
        }
set("value", 100);
set_weight(1100);
set("amount",1);                //�u�Ķq
set("bullet/damage",10);        //���ˤO
set("bullet/unit","��");        //�u�ĳ��
set("bullet/name","����");      //�u�ĦW��
set("type","small");            //�l�u����
setup();
}
