inherit ITEM;
inherit F_BULLET;
void create()
{

        set_name("�u��",({"clip"}));
        set("long","�@�Ӫ��ݻs���u���A���Y�˵ۥ�����j�����l�u�C�˶���O:(reload clip)\n");
        set_weight(1220);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("value", 200);
        set("unit", "��");
        set("amount",6);                //�u�Ķq
        set("bullet/damage",15);        //���ˤO
        set("bullet/unit","�o");        //�u�ĳ��
        set("bullet/name","�l�u");      //�u�ĦW��
        set("type","left_gun");            //�l�u����
        }
        setup();
}


