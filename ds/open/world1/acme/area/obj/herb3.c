inherit ITEM;
void create()
{
    set_name("�sŽ���Ū�", ({ "dragon flower","flower" }) );
    set_weight(10);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long","�o���Ǫᦳ�۳\\�h������Ž�A�b��ä�W�ո̳z�šA�Q���n�ݡC\n");
       set("unit","��");
       set("value",1);
    }
     setup();
}
