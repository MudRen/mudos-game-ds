#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�U��G�������ù�"NOR,({"TFT LCD moniter","TFT","LCD","moniter"}));
        set("unit", "��");
        set("long",@LONG
�@�ӳz�����G���ù��A���צ��@�ӤH���򰪡A���ݴN���@�Ӫ��A�ù���ܵ۳\�h���s�A�ثe���b���ն��q�C
�p�G�A�hĲ�I(push)���ǫ��s���ܡA�����w�|���ƻ�_�����Ʊ��o�͡C

LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()

{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        
        me=this_player();
        if(!arg) return notify_fail("�A���F�@�|��A�U��G���ù��W����]�S���o�͹L�D\n");
 if(arg=="dragon")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
      write(HIR"�A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�g�s�����j�U�F�C\n"NOR); 
      me->move("/open/world1/cominging/area/dragon/dragon");
         return 1;
 }
 if(arg=="sky")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIG"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�Ѧa�|���i���ѩж��j�F�C\n"NOR);
       me->move("/open/world1/acme/area/sky/room05");
         return 1;

 }
if(arg=="moon")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIC"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O��ڪ����F�C\n"NOR);
       me->move("/open/world1/acme/area/moon/room3");
         return 1;

 }
if(arg=="thief")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(MAG"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�s�骺�s��u�|�F�C\n"NOR);
       me->move("/open/world2/shengsan/aovandis/room100");
         return 1;

 }
if(arg=="god")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIM"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O���Z�Ъ��m�Z���a�F�C\n"NOR);
       me->move("/open/world1/acme/area/parlor");
         return 1;

 }
if(arg=="wind")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIG"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�e�������e���k�Ϥ��ФF�C\n"NOR);
       me->move("/open/world1/cominging/area/flurry49");
         return 1;

 }
if(arg=="bagi")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIR"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�K�������۫ΤF�C\n"NOR);
       me->move("/open/world1/tmr/area/s_house");
         return 1;

 }
if(arg=="bonze")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIB"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�ⶳ�x���j���_���F�C\n"NOR);
       me->move("/open/world1/acme/bonze/b16");
         return 1;

 }
if(arg=="mj")
 {
         message_vision(WHT"��M�U��G�������ù����e���W�Φ��@�����A$N�V�ù��̨��F�i�h�A�åB�����b�o�өж��̤F�C\n"NOR, me);
         tell_room(environment(me),me->name()+"���������b�ù����F�C\n",({me}));
       write(HIR"  �A���e�����H�C�C�a��{�A�ӧA�oı�A���e���N�O�ڤۤC�컷�񹣦W���±N�ΤF�C\n"NOR);
       me->move("/open/world1/tmr/area/mjroom");
         return 1;

 }


         
}
