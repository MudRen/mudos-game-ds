#include <ansi.h>
inherit NPC;
void create()
{
set_name("������",({"chiu yai je","chiu","yai","je"}));
set("long",@LONG
�o�O�@��h�����򪺶ǩ_�H��, �L���Z�\�L�v�۳q, �Q�K���ɤj�x
����, �Z�\�ѥH�C�k����, �@�������C�k��O�l���«C��Ӹg�L��
�W���ϸz�D�V��, �@�H�W���¹D��t�¦W���Q�U�j�s�s�s, �@�|�n
�W�j��, �M��, �p���L�H�T�����h����������L����p�����j, ��
�i�H���O�L���G�M�Y�ӧŮv���ۦP���W�r....
LONG
    );
 set("attitude","peaceful"); 
 set("title",HIR"����B��"NOR);
 set("age",36);
 set("gender","�k��");
 set("level",30);
 set_skill("sword",100);
 set_skill("sorgi_sword",100);
 map_skill("sword","sorgi_sword");
 set_skill("force",60);
 set_skill("parry",70);
 setup();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
}

