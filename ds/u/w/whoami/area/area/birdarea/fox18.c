#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"����"NOR);

 set("long",@LONG 
�g�L�����M�I�A�O���F�\�h�����A�ש�Ө쪰�޳̲`�B�C�A
���w�C�����J�·t���}�޷��A�V�`�J�}���A���߶V�`�J�A����
�ߡC���M���A�o�{�즳�@�ӤH�v�A����@�ݳ��M�O�@�ӥi�R���p
�k�ġA�ߤ����T�_�F�ðݡA������o�|�o���ƪ����޸�.....
LONG);
 
 set("no_clean_up", 0);
 setup();
}           

int valid_leave(object me, string dir)
{
   me = this_player();

  
     if (present("spider",environment(me)) && ( (dir=="north") ) )
       {
        tell_object(me,"����o�ӳå�ѨM�A�A���]�S�k�h�I\n");
       }
    else return ::valid_leave(me,dir);

}

