# FreeSpirit Delay — Liberty Music Software

Version 0.1.0 — prototype de développement, projet source JUCE/CMake indépendant.

## Interface

Surface vectorielle dessinée en C++, base logique 1502 × 992, rapport fixe, taille initiale 1126 × 744. Disposition reproduite d'après l'image fournie : en-tête, douze moteurs, carte des répétitions, trois vumètres, contrôles principaux, sept onglets, commandes de transport du delay, pied de page. La référence graphique n'est pas utilisée comme arrière-plan. Les commandes sont des composants JUCE associés à l'état du processeur. Libellés anglais pour conserver la référence visuelle. L'apparence exacte, les polices, la lisibilité et les limites de fenêtre doivent être vérifiées en hôte sur macOS et Windows.

## Contenu

- Douze algorithmes de départ : digital, analog, tape, ping-pong, stereo, slapback, multi-tap (4 taps), reverse, granular/diffuse, lo-fi, modulated et shimmer.
- 54 paramètres, synchronisation au tempo hôte ou tempo local, ratios, temps libre, filtres et coloration, modulation, ducking, largeur, panoramique, freeze, mute, wet solo, bypass, sécurité et réinitialisation.
- MIDI Learn sur les potentiomètres, sauvegarde des paramètres et des favoris dans l'état hôte, undo/redo, presets utilisateur en fichiers .fspreset.
- 100 recettes d'usine distinctes réparties dans onze catégories ; navigateur par menus et recherche. Les presets n'ont pas encore été auditionnés individuellement.
- Carte des répétitions = prévision temporelle théorique ; les trois indicateurs sont alimentés par le DSP.

## Compiler

CMake 3.22+, C++17, JUCE 8.0.8. Pour un JUCE déjà présent, ajouter -DJUCE_DIR=/chemin/vers/JUCE à la commande CMake.

macOS ARM64 : cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES=arm64

Windows x64 : cmake -S . -B build -A x64

Puis : cmake --build build --config Release --parallel 3

Tests : ctest --test-dir build -C Release --output-on-failure

Sorties attendues : build/FreeSpiritDelay_artefacts/Release/ — VST3, AU (macOS uniquement), Standalone. GitHub Actions construit pour les deux OS et exige un artefact avant de réussir. Pas de signature ni de notarisation à ce stade.

## Limites

Compilation JUCE, validation en hôte, qualité sonore et fidélité graphique finale à vérifier. Les algorithmes granular, reverse et shimmer sont des prototypes à fenêtres croisées ; les filtres sont simplifiés. Ne pas considérer cette version comme une version commerciale validée.
