/**
 *	Shadow ���H�� - �P�j�T(�����H��) - zhou.c
 */

#include <ansi.h>
inherit NPC;

void create()
{
	/*  �H���򥻳]�w */
  set_name( "�P�j�T", ({ "aunt zhou", "zhou", "aunt"}));
  set("long",@LONG
    �@�ӶǲΪ��������k�A���M�~�����j�A���g�~�֤몺�u�@�o�ϱo
�o�ݦ����������C���W���²�檺�A���A�S���h�l���t���A�@�ݴN��
�D�䬰�H���뤣�n�Q���A�Q���O�ݩ��d�}���������k�ʡC�M�ӡA�o
������W�o���ۤ@�u�@���_�����K�٫��A���M�w�g�ƤF��A�����M�O
�i�o�ܦn�A�ϩ��S�O����P�j�T�������I
LONG
	);
  set("level", 20);
  set("gender", "�k��");
  set("race", "�H��");
  set("age", 37);           
  set("combat_exp", 3700);       /* �Լ� */
  set("evil", 30);               /* ���c�� 30 (�������c, �t���}) */
	set("attitude", "peaceful");   /* �ũM�� NPC */
	set("chat_chance", 5);
  set("chat_msg", ({
		"�P�j�T�H�H�a�ĤF�f��...\n",
		"�P�j�T�Ⲵ�Ŭ}�a�����ۻ���...\n",
		"�P�j�T���ۻy�D�G�u���b�H�b�A�����H�`�v...\n",
	}) ); 
   
	
	/* ������Ȫ��T�� */
	
	set("talk_reply", "�n�H���Ӧn�k�O�H���h�F�V�Ҫ��k�H�n��ˤ~�n�o�_�өO�H");
		
	set("inquiry/�K�٫�","�o�u�K�٫��O�ڤV�ҷ�~�e�ڪ��w�����A�L�����L�u���b�H�b�B�����H�`�v�C�{�b�ڤV�����M�����F�A���ڬ۫H..�`���@�ѥL�|�^�Ӫ��I");
	set("inquiry/�V��", "��............�@�~�h�e�A�ڤV�һ��n�X�������A�{���e�٫ܰ����a��ڻ��G�u�Q�l..�ګܧִN�|���A�L�n�ͬ��F..�v�S�Q��A�ۨ��ѥX��������ڤV�ҴN�A�]�S�^�ӹL�F..");	
  setup();
  
  add_money("coin", 300);    //�a����
  
	// carry_object("/u/l/luky/npc/item/dump"); /* ��a�K�٫��@�� */
	
}


