/**
 * サンプルカーネルモジュール
 * - モジュール作成の勉強
 *
 * 概要
 * - 全processを一覧表示する
 *
 * Create Date : 2026/05/30
 *
 * Created By : Revi
 */

/**
 * 出力フォーマットの定義
 */
#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__

/**
 * ヘッダの定義
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>  /* タスクリスト取得マクロ */

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Sample module using current");
MODULE_AUTHOR("Revi");

static inline void get_task_list(void)
{
	struct task_struct *prc;

	for_each_process(prc) {
		pr_info("task : pid=%d, comm=%s, mm=%px, state=%c\n",
				task_pid_nr(prc),	/* スレッドID */
				//task->pid,
				prc->comm,		/* プロセス（スレッド）名 */
				prc->mm,		/* プロセス仮想アドレス空間のポインタ */
				prc->__state		/* プロセスの状態 */
		);
	}
}

static int __init list_init(void)
{

	pr_info("Install Module\n");
	get_task_list();
	return 0;
}

static void __exit list_exit(void)
{
	pr_info("Remove Module\n");
	get_task_list();
}

module_init(list_init);
module_exit(list_exit);
