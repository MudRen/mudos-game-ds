#include <ansi.h>
#define SECRET_ROOM "/open/world1/acme/area/moon/room8"
inherit ITEM;
void create()
{
    set_name(HIR"�����u�\\�Y"NOR,({"The Skeleton Of Fofo","skeleton"}));
        set("unit", "�y");
        set("long",@LONG
                          �d�f�h�i�i�h�f�d
                        �h�i�i�i�i�i�i�i�i�h
                       �i�i�i�i�i�i�i�i�i�i�i
         �e          �i�i�e�i�i�i�i�i�i�i�e�i�i
         �l         �i�i�i      �i�i     �i�i�i
         �i        �m�i         �i         �i�i
         �e         �i                       �i
      �e �e �e �d  �i                       �i
      �m �m �m �f   �i          �i          �i
   �e�i�m�i �i �m   �i�e     �i  �i     �e�i
  �i�e�e�e�e�e�e�e   �d �i�e�i      �i�e�i �d
 �i �i �i �i �i �i    �i�e�i�i      �i�m�e�i
  �m�i�i�i�i�i�i�i      �i �i�i    �m�m �i
 �i �i�i�i�i�i�i        �i  �m�m�f �m�m �i
    �i�i�i�i�d�m        �i            �i
      �i�d �i�i           �i �m�m �m�m�i
      �i�i �i�i              �i�i�i�i

�o�O��(Fofo)�Ȧۤv���L���ͨƥ��������ҫ��u�\�Y�A�������i�ïu
LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string arg)
{
        object me;
        
        me=this_player();
        if(arg!="skeleton")
        {
                notify_fail("�A�n�N����?\n");
                return 0;
        }
        tell_room(environment(me),me->name()+"Ĳ�N�F�@�U�����u�\\�Y�C\n",({me}));
        if(CLUB_D->check_member("moon",getuid(me)) > 1 || wizardp(me))
        {
                write("�A�Ԥ���Ĳ�N�F�@�U�����u�\\�Y�C\n");
                if(me->can_move(SECRET_ROOM))
                {
                        tell_room(environment(me),me->name()+"��M�����F�C\n",({me}));
                        write("���M�|�P�����}�}�j..\n");
                        me->move(SECRET_ROOM);
                        write("�A�o�{�ۤv�Ө�@�ӯ������a��C\n");
                        tell_room(environment(me),me->name()+"��M�X�{�b�o�̡C\n",({me}));
                        return 1;
                } else
                {
                        write("���G����Ƴ��S�o��..�Aı�o���G���ӹ�l�C\n");
                        return 1;
                }

        } else 
        {
                write("�A�Pı�u�\\�Y���G��A���F�@�U...���ƣ�~~~\n");
                return 1;
        }
}

