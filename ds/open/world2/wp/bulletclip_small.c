//bag.c by luky
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name("�T���̤l�u�u��",({"bullet-3mm clip","bullet","clip"}));
        set_weight(900);
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("material", "iron");
        set("long",@LONG
�@�Ӫ��ݻs���u��, �C�@�ռu���X�t�ɳ��˦��K�o�l�u�C
�˶���O:(reload clip)
LONG);
        }
set("amount",8);		//�u�Ķq
set("bullet/damage",22);	//���ˤO
set("bullet/unit","�o");	//�u�ĳ��
set("bullet/name","�T���̤l�u");	//�u�ĦW��
set("type","small");		//�l�u����
setup();
set("value", 400);
}

