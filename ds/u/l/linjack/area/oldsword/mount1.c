#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","�s�V��");
 set("long",@LONG
�A�Ө�F�o�k�����̳��ݤF, �A���|�P�ݤ@��, ���G�����٦��@
�ǥ��x�a�i�H���@�ǤH���b�o��. �o�̧N���B�B, �A���T���F�ӴH��,
�Y���F���h, �u�O�@�B�ݤ�X�鸨���n�a�I! ����Ţ�n�A���U��,
�ӧA�������h�L���e�s, �O�H���m����. ���L�p�ߧO�L�U�h�F, �U�h
�i�N�S�o�ϤF! �A�������, ���@�y���j���p���j�F, ���o�Xģ����
�ȥե��u, ���ӴN�O�ǻ������j�C�F�F!
�A�oı�F�䪺�s���U�n�����ӹ�l. ���L�A���Ӫ����U�h..
LONG
    );
 set("exits",([
               "west":__DIR__"oldsword",
               "southdown":__DIR__"mount2",
               "eastdown":__DIR__"secret1",]));
 set("no_clean_up", 0);
 setup();
}
int valid_leave(object me, string dir)
{
 if( dir=="eastdown" && !(me->query_temp("hall",1)) )
  return notify_fail("�A�Q���U�h? �o���g��?\n");
 else if( dir=="eastdown" && me->query_temp("hall",1) )
  write(HIW"\n�A�p���l�l���a���ӤU ...\n\n"NOR);
 return ::valid_leave(me, dir);
}


