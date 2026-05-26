# 避障车 FPGA 项目

基于野火升腾 Mini FPGA 开发板的数电课程项目。项目使用 SystemVerilog 实现一个 6 列、3 层显示的“避障车”小游戏，玩家通过按键控制车辆左右移动，在数码管上躲避下落障碍，并配合 LED 生命值显示与无源蜂鸣器音效完成完整游戏流程。

当前版本已经整合：

- 30 关障碍流程
- 4 次生命值机制
- 背景音乐、胜利音效、失败音效、碰撞短音
- 数码管动态扫描显示
- LED 呼吸与扣血爆闪效果
- 安全路径可达的障碍生成策略

## 开发环境

- Vivado 版本：`2023.2`
- 目标开发板：野火升腾 Mini FPGA
- 主要语言：SystemVerilog

## 项目特点

- 单时钟同步设计，所有逻辑统一运行在 `50MHz` 主时钟下
- 低速行为通过 `tick enable` 控制，不额外派生新时钟
- 游戏逻辑、显示逻辑、按键处理、音效播放拆分为独立模块
- 蜂鸣器使用“音符表 + 节拍表 + 方波分频”方案，避免大体积 PCM ROM
- 工程内保留了音乐生成脚本和 WAV 试听文件，便于继续改音效

## 仓库结构

```text
.
├─ docs/                         设计说明、音乐修改记录、答辩参考
├─ music/                        原始音频、试听 WAV、候选音乐
├─ tools/                        蜂鸣器音乐生成脚本
├─ vivado/Obstacle_Avoidance_Car_Project/
│  ├─ Obstacle_Avoidance_Car_Project.xpr
│  └─ Obstacle_Avoidance_Car_Project.srcs/
│     ├─ constrs_1/new/          XDC 约束
│     └─ sources_1/new/          SystemVerilog 源码
├─ 题目/                         原始题目与需求材料
└─ 参考资料/                      开发板与参考书 PDF
```

## 核心模块

主要源码位于：

`vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/`

- `obstacle_car_top.sv`
  顶层集成模块，连接按键、游戏核心、数码管、LED 和蜂鸣器
- `obstacle_game_core.sv`
  游戏状态机、障碍生成、碰撞判定、胜负逻辑
- `sevenseg_scan.sv`
  6 位数码管动态扫描与 A/G/D 段显示映射
- `hp_led_pwm.sv`
  生命值 LED 呼吸与扣血爆闪
- `key_debounce.sv`
  按键同步、防抖、单周期按下脉冲
- `tick_gen.sv`
  统一 tick 使能发生器
- `buzzer_note_player.sv`
  无源蜂鸣器旋律与短音播放器

## 硬件与操作说明

- 开发板：野火升腾 Mini FPGA
- 系统时钟：`50MHz`
- 按键：
  - `KEY1`：右移
  - `KEY2`：左移
  - `KEY3` / `KEY4`：开始游戏
- 显示：
  - 数码管 6 列表示横向位置
  - `A/G/D` 三段表示障碍的上、中、下三层
  - LED 表示剩余生命值
- 音效：
  - `RUN` 状态循环播放背景音乐
  - 普通碰撞播放短音
  - `WIN` / `LOSE` 播放不同结算音效

## 快速开始

### 1. 打开工程

使用 Vivado 打开：

`vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.xpr`

### 2. 建议检查顺序

1. 确认 `Sources` 中包含 `buzzer_note_player.sv`
2. 确认 `Constraints` 中启用了 `obstacle_car.xdc`
3. 运行 `Synthesis`
4. 运行 `Implementation`
5. 生成 bitstream 并下载到板卡

### 3. 前端语法检查

如果只想做 RTL 语法检查，可以运行：

```bash
xvlog -sv -i vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/tick_gen.sv \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/hp_led_pwm.sv \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/key_debounce.sv \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/obstacle_game_core.sv \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/sevenseg_scan.sv \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/buzzer_note_player.sv \
  vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/obstacle_car_top.sv
```

## 音乐资源与生成

当前蜂鸣器方案不直接综合 MP3/PCM 音频，而是把旋律写成音符表后生成播放器源码。

关键文件：

- `tools/generate_buzzer_note_player.py`
- `music/note_player_preview/see_you_again_note_player_preview.wav`
- `music/note_player_preview/cancan_win_note_player_preview.wav`
- `music/note_player_preview/fail_note_player_preview.wav`

重新生成蜂鸣器播放器与试听文件：

```bash
python tools/generate_buzzer_note_player.py
```

这会同步更新：

- `buzzer_note_player.sv`
- 背景音乐试听
- 胜利音效试听
- 失败音效试听

## 文档导航

- 设计实现说明：[docs/避障车SystemVerilog实现说明.md](/C:/Users/32171/.codex/worktrees/d095/V1/docs/避障车SystemVerilog实现说明.md)
- 蜂鸣器音乐修改汇总：[docs/蜂鸣器音乐修改汇总.md](/C:/Users/32171/.codex/worktrees/d095/V1/docs/蜂鸣器音乐修改汇总.md)
- 验收答辩参考：[docs/验收答辩常见问题与参考回答.md](/C:/Users/32171/.codex/worktrees/d095/V1/docs/验收答辩常见问题与参考回答.md)
- 题目需求：[题目/避障车需求与设计文档.md](/C:/Users/32171/.codex/worktrees/d095/V1/题目/避障车需求与设计文档.md)

## 演示资源

- 项目演示视频：[obstacle_car_demo.mp4](/C:/Users/32171/.codex/worktrees/d095/V1/demo/obstacle_car_demo.mp4)

## 当前状态

- 默认关卡数量为 `30`
- 默认背景音乐已开启
- 胜利/失败音效使用短促提示音，而不是长旋律
- 障碍生成逻辑已经过多轮调整，目前目标是在“可通关”和“需要操作”之间取平衡

仓库中保留了历史实现报告。此前一次 `impl_1` 报告曾出现时序违例，最差路径集中在 `obstacle_game_core` 的障碍生成组合逻辑。后续如果继续优化实现时间或收敛时序，建议优先检查该模块。

## 后续可继续做的事

- 继续简化 `obstacle_game_core` 的关键路径，改善实现时间
- 调整障碍密度和安全路径策略，继续打磨手感
- 增加 testbench，覆盖更多碰撞与边界场景
- 为不同场景准备更多蜂鸣器可用的旋律模板
