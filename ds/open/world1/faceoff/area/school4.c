#include <path.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�˪ŮѰ|�G��"NOR);

 set("long",@LONG
���ߧA�ש�q�L�F�g�c, �˪ŮѰ|�w�g�S������i�H�ЧA��
�F��F, �Ʊ�A�w������L�M�q, ��uDs���W�h, �����@�ӥO
�H�q�ت��n���a! ���O! ���O! 
�x? �A�ݨ�̫�o���٦����O�l(board)....
LONG
    );
 set("exits",([ "in":TMR_PAST+"area/inn_2f",
    ]));
 set("item_desc",([
"board":"�A�J�Ӫ��ݤF�ݧi�ܪO, �o�{�W���o�˼g��:\n\n
�O�o�h��help, �hť�Ѫ��a����, �԰O�u�V�O�䵪��, ���n�ݵ��סv\n
�����|�X�� MUD�����N�P! ����? �Q�n�t����....���ǤH�n�ߪ���\n
�F�@�I����, �A�N�ݬݧa!\n
�j�N�F�誺����:\n
      �K����, ¾�~: �Z��, ���O: ��ťή�, ���Ų�����i�m�j�k\n
          �J������: �����Ѥ�ᥴ:join �K����, ���Ѥ�ܭn��\n
	 	    �l�s�A���@�y�ٴ��K��������, ť�����Ѥ妳\n
		    �e�i�Ѫk���s�������s��A, �N���b�����a, \n
            �γ\\..........\n
	  �����a�I: �q�¤ѼӪ��񪺤j���������䨫�h��ݬݧa..\n
�����? �K�����A�٤��n�m? �n�a, �A�i�D�A�@�I, �Ь�(board2)..\n",
"board2":"�n�a, �N�A���A�ݤ@�Ǵ����P....�A���|�ڥi�����A��! \n\n
      ���Z��, ¾�~: �D�h, ���O: �H�k�N���D�n, �C�k�����U����\n
	  �J������: ������ѫ��_�誺�Ѧ��u�W���v, ���|��? ��\n
		    �v�Q��k. �h�լd�@�U�r���᭱�۾������Ⱦ�\n
                    �a....�~�����Ӷ¦�ѤH�@���Q���D�۾�����\n
		    �Ⱦ�, �A�N���L���D�L�N�|���������A�@���F\n
                    �F..�M��h�ѫ����n��....����ۤv��! \n",
]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}
void init() { this_player()->set("not_newbie",1); }
