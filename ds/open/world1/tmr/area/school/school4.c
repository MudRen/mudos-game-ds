#include <path.h>
#include <login.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�s��ЫǤG��"NOR);

 set("long",@LONG

  ���ߧA�ש�q�L�F�g�c, �s��ЫǤw�g�S������i�H�ЧA���F��F
, �Ʊ�A�w������L�M�q, ��uDs���W�h, �����@�ӥO�H�q�ت��n
���a! ���O! ���O! �x? �A�ݨ�̫�o���٦����O�l([1;35mboard[0m)�C
                                                  ��
�ġ�                                    �ġġġĢ�
" �y���ġġġġġġġġġġġġġġġĢ��j'    "�j��
: �y�y=" '                         "" �j�j  "  :�j�i
= �y�y==-  "           "'           =-�j�j     =�j�i
: �y���áááááááááááááááâ��j   -==�j�i
�á�                                    �áááâ��i
                                                  �âj
                                                    ��

LONG
    );
    
 set("exits",([ "out":START_ROOM_PAST,
    ]));
 set("item_desc",([
"board":@BOARD

�A�J�Ӫ��ݤF�ݧi�ܪO, �o�{�W���o�˼g��:

  �O�o�h��help, �hť�Ѫ��a����, �԰O�u�V�O�䵪��, ���n�ݵ��סv
�����|�X�� MUD�����N�P! ����? �Q�n�t����....���ǤH�n�ߪ���
�F�@�I����, �A�N�ݬݧa!


�j�N�F�誺����:

	�i�K�����j      ¾�~: �Z�� 
	���O: ��ťή�, ���Ų�����i�m�j�k
	�����a�I: �q�¤ѼӪ��񪺤j���������䨫�h��ݬݧa..
	�J������: �����Ѥ�ᥴ:<join �K����>, ���Ѥ�ܭn���l
                �s�A���@�y�ٴ��K��������, ť�����Ѥ妳�e�i��
                �k���s�������s��A, �N���b�����a, �γ\......
      
    �����? �K�����A�٤��n�m? �n�a, �A�i�D�A�@�I, �Ь�([1;35mboard2[0m).

BOARD
,
"board2":@BOARD2

  �n�a, �N�A���A�ݤ@�Ǵ����P....�A���|�ڥi�����A��!
  
	�i���Z�Сj	¾�~: �D�h
	
	���O: �H�k�N���D�n, �C�k�����U����
	�J������: ������ѫ��_�誺�Ѧ��u�W���v, ���|��? �ۤv
		  �Q��k. �h�լd�@�U�r���᭱�۾������Ⱦ��a..
		  �~�����Ӷ¦�ѤH�@���Q���D�۾������Ⱦ�, �A
		  �N���L���D�L�N�|���������A�@���F�F..�M��h
		  �ѫ����n��....����ۤv��!
	  
    	����L���n�u�W�����Х� �i[1;32m help [0m�j ���O. 
    	���̷s�����s����n�O �i[1;33m help start_1 [0m�j
	  
	[1;36m �n��! ���A�bDS���_�I�ͲP�@�����Q![0m

					     - DS �ζ��q�� 1999-
BOARD2
,
]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}

void init()
{
	this_player()->set("quest/not_newbie",1);
	this_player()->delete("newbie");
}
