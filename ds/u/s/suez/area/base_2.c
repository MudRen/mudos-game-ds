#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", CYN"���s��"NOR);
	set("long", @LONG
�o�̦��G�O�ӭ��n���a��A�]���o�̤��ȥ|�P�H�۶����A���J��e
�ɡA�Q������C�M���A�Ҭݨ쪺²���g��²���O���[���O�C�b�A���e�O
�Ӥ�[�A�[�W�\�F�X���Z�ǱK�D�A���O�n���֤F�X���A�Ӧb�A����h���@
�Ӥp�۱�A�۱�W����G���Ӿ����A�γ\�A�i�H�W�h(climb)�ݬݡC
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "east" : __DIR__"base_5",
               ]));
         set("item_desc",([
        "�J��":"�o�̪��J��Q������A���O�A�`ı�o���̩ǩǪ��C\n",
        "��[":"��[�W���Z�ǱK�D���e���Q��²��A�A���άݤ]�|�C���A�̦����Ȫ����X���O�H\n",
         ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
         int t;
        object me;
        me=this_player();
        if(arg != "�۱�") return 0;
        message_vision( HIG "$N���W�۱���Mı�o�}�U�@�P�A�Y����M�}�F�@�Ӭ}�A$N�K�V�}�����h�C\n\n" NOR ,me);
        me->start_busy(3);
        call_out("domessage",3,me,3);

        message_vision( HIG "$N��ӤH�����b�}����A�۾��S�F�@�n���W�F�C\n\n" NOR ,me);
      me->move(__DIR__"little_path");
        return 1;
}
int domessage(object me,int b)
{
 if(b==2) 
        tell_object(me, HIB "�A���ڨ����A�@��ı�o�n�������n�b�����F�F���T�C\n\n" NOR );
  else if(b==1) 
        tell_object(me, HIB "�A�ש󨫨�F���Y�A�ݨ�e�褣���B���ӥ۽��L�C\n\n" NOR );
  else  if(b==0) 
        {
        tell_object(me,HIY "�A��ʤF�۽��L�A�ۤ��ǨӤF�@�}������ʪ��n���A��M���e�@�����G�I\n\n" NOR );
        this_object()->delete("user");
        me->move(__DIR__"hotel_room4");
       tell_room(environment(me),me->query("name")+HIY"��M�b�@�n���T��X�{�I\n"NOR,me);
        return 1;
        }
b--;
me->start_busy(3);
call_out("domessage",3,me,b);
}