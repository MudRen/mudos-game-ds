#include <ansi2.h>
inherit ITEM;
void create()
{
  set_name("123123", ({ "ch","ccchhh" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","\n");
  setup();
}
void init()
{
  add_action("do_ch1","ch1");
}

int do_ch1(string arg)
{
        object me=this_player();
        me->set("env/msg_mout",HIW"\n"
"[0;1m�[1mz[0m�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{ \n"
"�x   �p�J��                     �x\n" 
"�x       ���h�O���a��           �x\n" 
"�x            ��  �m  �F        �x\n" 
"�x      ���i�i��                �x\n"
"�x      �i    ���m              �x\n"
"�x      �����_���m              �x\n"
"�|�w�w�B��  �f���w�w�w�f�w�w�w�w�}\n"
" �ááâ��áh�â��ááááááá�\n"
"         �j  �y\n"
"         ���â�\n"); 
        me->set("env/msg_min",HIW"\n"
"[0;1m�[1mz[0m�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{ \n"
"�x   �p�J��                     �x\n" 
"�x       ���ӳo��               �x\n" 
"�x            ��  �m  �F        �x\n" 
"�x      ���i�i��                �x\n"
"�x      �i    ���m              �x\n"
"�x      �����_���m              �x\n"
"�|�w�w�B��  �f���w�w�w�f�w�w�w�w�}\n"
" �ááâ��áh�â��ááááááá�\n"
"         �j  �y\n"
"         ���â�\n");
 
me->save();
return 1;
}
