inherit ITEM;
void create()
{
        set_name("�������߯�", ({ "red heart herb","herb" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long","�o�O�@�観�������l�A�B���ߤ����@�������A���p��C\n");
           set("unit","��");
           set("value",1);
        }
     setup();
}
