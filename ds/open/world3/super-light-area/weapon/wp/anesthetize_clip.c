inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("�·��u",({"anesthetize clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�������·��ĪG���l�u, �Шϥ�reload���.\n");
        }
set("value", 50);
set_weight(1000);
set("amount",1);                //�u�Ķq
set("bullet/damage",20);        //���ˤO
set("bullet/unit","��");        //�u�ĳ��
set("bullet/name","�·��u");      //�u�ĦW��
set("type","small");            //�l�u����
setup();
}


