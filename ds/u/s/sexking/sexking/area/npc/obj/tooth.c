#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"�j�a����"NOR,({ "the earch's tooth","tooth", }));
        set_weight(1000);
        set("armor_prop/str",1);
        if( clonep() )
        set_default_object(__FILE__);
        else
        {
                set("long",HIG"�@���s�뫬�������A���o�X"HIC"�N�N����"HIG"�A�A����\n���P�����j�j�O�q�A���]�P����W�����P�y�S�C\n"NOR);
                set("unit","��");
                set("value",1000);
        }
        setup();
}
void init()
{
 add_action("do_l","l");
 add_action("do_look","look");
}
int do_l(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg!="�N�N����" )
      {
                notify_fail("�A�n�ݤ���?\n");
                return 0;
      }
write(HIC"�o�N�N�����Q���g�H�A�̭����G���@��[��]�r�A�O�H�ʫ䤣�o��ѡC\n"NOR,this_player());
return 1;
 } 
int do_look(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return 0;
        if( arg!="�N�N����" )
      {
                notify_fail("�A�n�ݤ���?\n");
                return 0;
      }
write(HIC"�o�N�N�����Q���g�H�A�̭����G���@��[��]�r�A�O�H�ʫ䤣�o��ѡC\n"NOR,this_player());
return 1;
 } 
