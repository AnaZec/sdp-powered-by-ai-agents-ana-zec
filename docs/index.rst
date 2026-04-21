Minesweeper Field Processor Documentation
=====================

The Minesweeper Field Processor kata is a text-based problem that transforms a given minefield into a processed field where each cell contains either a mine (*) or the number of adjacent mines.

The system reads an input grid, applies deterministic processing rules, and outputs a fully annotated field, making it a suitable exercise for practicing TDD/BDD, input/output processing, and modular system design.

This repository provides the official documentation for the kata, generated using Sphinx.

.. toctree::
   :maxdepth: 2
   :caption: Overview:

   README

.. toctree::
   :maxdepth: 2
   :caption: Architecture:

   architecture/01-introduction-and-goals
   architecture/02-constraints
   architecture/03-context-and-scope
   architecture/04-solution-strategy
   architecture/05-building-block-view
   architecture/06-runtime-view
   architecture/07-deployment-view
   architecture/08-cross-cutting-concepts
   architecture/09-architecture-decisions
   architecture/10-quality-requirements
   architecture/11-risks-and-technical-debts
   architecture/12-glossary

.. toctree::
   :maxdepth: 2
   :caption: User Stories:

   user-stories/README
   user-stories/input
   user-stories/proc
   user-stories/output

Indices and tables
==================

* :ref:`genindex`
* :ref:`search`
