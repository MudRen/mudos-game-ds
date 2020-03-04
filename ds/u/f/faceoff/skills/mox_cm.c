#include <ansi.h>
inherit SSERVER;
inherit SKILL;

int cast(object me, object target, string arg)
{
        int sk,i,inn,cost,he,si;
        object *enemy;
        sk=me->query_spell("moxibustion");
        inn=me->query_int();
        if( environment(me)->query("no_cast") ) 
                return notify_fail("�o�̤���w�b�C\n");
        if( environment(me)->query("no_magic") ) 
                return notify_fail("�o�̤���w�b�C\n");

        if( sizeof(me->query_temp("is_busy")) )
                 return notify_fail("�A�{�b���b���A�L�k�ϥΪ��ްw�b�@�C\n");

        if( !present("needle",me) )
                return notify_fail("�A�������w�~��ϥΰw�b�@�C\n");

        if(me->query("mp") < 20)
                return notify_fail("�A�ثe�����骬�A�L�k�ϥΡu���ްw�b�v���C\n");
        if(me->is_fighting() )
                return notify_fail("�԰����A�L�v�ϥΡu���ްw�b�v.");

        if( !me->query("env/moxibustion") || me->query("env/moxibustion") == 0 || me->query("env/moxibustion") > 4 )
                return notify_fail("�Х� set moxibustion 1 �ϥΪ��ްw�b�Ĥ@���\�O, �p�G������help moxibustion.\n");

        if( (int)me->query("env/moxibustion") == 1) // ����Z
        {
                cost=(he)-(inn)-(sk)/2;
                si=random(inn);
                he=(inn)*2+(sk)*2;
                message_vision(CYN"\n$N���ؾ���, �N��l�B��⤤�Ȱw, �ǳƨϥX�|���w�b���u"+HIC+"�i����j"+NOR+"�v�Z�C\n"NOR,me);
                message_vision(CYN"\n$N���M�M�S�@�n, �⤤�Ȱw���I�߯�, �ʦ�F�ˤf���˶� !!\n"NOR,me);
                message_vision(CYN"\n$N���ˤf�������F��y....\n"NOR,me);
                me->start_busy(2);  //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                me->receive_heal("hp",he); // �^�_HP
                me->improve_skill("moxibustion",si);
        }
        
        if( (int)me->query("env/moxibustion") == 2) // ����Z
        {
                cost=(he)-(inn)-(sk)/3;
                si=random(inn);
                he=(inn)+(sk)*2;
                message_vision(CYN"\n$N����B�l, �l�z����, �ǳƨϥX�|���w�b���u"+HIC+"�i����j"+NOR+"�v�Z�C\n"NOR,me);
                message_vision(CYN"\n$N���M�N�⤤�Ȱw�ϱo�ַ�, �I�M���нѥ� !!\n"NOR,me);
                message_vision(CYN"\n$N�P��@�ѷx��ۤ��Ъ@�W....\n"NOR,me);
                me->start_busy(2); //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                me->receive_heal("ap",he); // �^�_HP
                me->improve_skill("moxibustion",si);
        }

        if( (int)me->query("env/moxibustion") == 3) // �}�ѳZ
        {
                cost=(he)-(inn);
                si=random(inn)+6;
                he=(inn)*2+(sk)*2;
                message_vision(CYN"\n$N�B�_�����F�O, �u��$N�Y���}�}�շϫ_�X, �ǳƨϥX�|���w�b���ť\�O�u"+HIC+"�i�}�ѡj"+NOR+"�v�Z�C\n"NOR,me);
                message_vision(CYN"\n$N���M�N�⤤�Ȱw�ϱo���p���s, �b�ɱN�����G�ߥ��q !!\n"NOR,me);
                message_vision(CYN"\n$N�uı�n���@�Ѻu���y�L����, �κZ�L��! \n"NOR,me);
                me->start_busy(3); //�I�k�ʧ@�ɶ�
                me->receive_damage("mp",cost); //�I�k��MP
                me->receive_heal("ap",he); // �^�_AP
                me->receive_heal("hp",he); // �^�_HP
                me->improve_skill("moxibustion",si);
        }
        return 1;
}
