inherit ITEM;
void create()
{
    set_name("�f�H�F�Ǯ�", ({ "lacking root","root" }) );
    set_weight(10);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long","�o�O�@�ڧG���ǨF���d�~���F�۪��ڡC\n");
       set("unit","��");
       set("value",1);
    }
     setup();
}
