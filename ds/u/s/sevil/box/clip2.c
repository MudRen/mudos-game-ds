inherit ITEM;
inherit F_BULLET;
void create()
{

        set_name("���b",({"clip"}));
        set("long","�@�Ӫ��ݻs�����b�A�㦳�j�P�������ʡC�˶���O:(reload clip)\n");
        set_weight(1220);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("value", 200);
        set("unit", "��");
        set("amount",6);                //�u�Ķq
        set("bullet/damage",100);        //���ˤO
        set("bullet/unit","�o");        //�u�ĳ��
        set("bullet/name","�l�u");      //�u�ĦW��
        set("type","left_gun");            //�l�u����
        }
        setup();
}


