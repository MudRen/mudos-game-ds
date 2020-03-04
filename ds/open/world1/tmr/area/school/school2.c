#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�s��ЫǪŤ��x�|"NOR);

 set("long",@LONG
 
       �z�s�{          �z�s�{                  �j
       �u�q�t          �u�t�x                  �j
       �|�r�}          �|�r�}[1;32m�\[m   �š�         �j
��                         [1;32m��[1;31m��[1;32m��[m ��  ��       �j
����    �z�w�w�w�{          [1;32m/_|_*[m �i��  ��___O_�j
�����šâx[1;33m�ФW��[m�x�áááá� \_/�â��i��  ��/Y\��
�â����Ţ|�w�s�w�}                  ���i��  �áááâ�
  �â���    �r                        ���i�i�i�i�i�i�i
    �â�                                ���i�i�i�i�i�i
�áá�
  �A���i�F�t�@���ж�, �o�{�o�̬O�@�B�Ť��x�|, ��B���y�᭻, 
�A�ݨ쪺��c��M������P, �Ѧ��i�H�ݥX�o�̦��G�S���|�u����,
�A�A�J�Ӥ@��, �o�{�b���O(flowers)���@�ڬ�_�����Y(wood)�W��
�g�F�Ǧr, �A�@�Q�F�Q.... ��F, ���ݬݧa....

LONG
    );
 set("exits",([ "west":__DIR__"school1.c",
                "up":__DIR__"school3.c",
    ]));
 set("item_desc",([
 	"flowers":"�A�ݨ���O�����@�ڤ��Y(wood)..\n",
        "wood":@WOOD
        
  �A�ݤF�ݳo�ڤ��Y, �o�{�I���O����, �W���g��: �԰��ޥ�, ....
�z! �᭱���r�ݤ��M�F....����O? �ոլݥJ���ˬd(search wood)
�@�U�a!
        
WOOD
,
        "book":@BOOK
        
  �o���ѬO�n�ЧA�p��԰�, �]�O�ѯ��Q�A�ۤ߷P�ʦӱ��U����..��
��A�n�n�ݤ@�U. �����U search flowers �o�ӫ��O. �|�]�X�@����
��, �復�Ukill���O, ���N�O�԰�����p, �԰��e������considerŲ
�w�@�U�ĤH, �A�}��, ���U�@�����}�`����O? �A����|��@�Ӧ�
����J�����a��....�䤤�@�ӬO�ͩR����, �@�ӬO���`����, �o���p
�A, ���Ӫ��D�n�����@�ӧa!?�ϥ����F�A�չ�...., ��F, �����ĤH
�ᤣ�n�ѰO�^�m(sac)�L������(corpse)��!���i�O�m�O�H�������H��
�����...

[����: �}�ԫe����J<wimpy 50>�ӳ]�w�۰ʰk�]�O����w�������k]
[����: �J��i�ê��a�褣���ϥ� search here �J�Ӫ��j�d�@�U�a!]

BOOK
,
    ]));
    
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

int do_search(object me,string arg)
{
        object butterfly;
	if(arg == "flowers" && !present("butterfly", this_object()))
        {
                if(me->query("find_butter"))   //change by Kkeenn because Legand��search robot��exp
                {
                        message_vision("$N�J�Ӫ��b���O���M��F��, ���O����M���X�@���Q���O�j�ƽ����C\n\n",me);
                        butterfly=new(__DIR__"npc/butterfly2.c");
                        butterfly->move(__DIR__"school2.c");
                        me->set("find_butter",1);
                        return 1;
                }
                if(!me->query("find_butter"))
		{
        		message_vision("$N�J�Ӫ��b���O���M��F��, ���O����M���X�@���p�����C\n\n",me);
			butterfly=new(__DIR__"npc/butterfly.c");
			butterfly->move(__DIR__"school2.c");
                        me->set("find_butter",1);
			return 1;
		}
	}
	if( arg == "wood")
	{
		tell_object(me,"�N�b�A���n�J���ˬd���Y��..���M, ��! ���@�n, �@����(book)���F�U��..\n�ݬݤW���g�Ǥ���a(look book).\n");
		return 1;
	}
	return 0;
}
