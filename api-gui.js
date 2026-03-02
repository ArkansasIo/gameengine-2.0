/**
 * LunaLite API GUI - Interactive JavaScript
 * RPG Maker MZ Styled API Reference Interface
 */

class LunaLiteAPIGUI {
    constructor() {
        this.init();
    }

    /**
     * Initialize the GUI
     */
    init() {
        this.setupEventListeners();
        this.setupSmoothScroll();
        this.loadInitialState();
    }

    /**
     * Setup event listeners for interactive elements
     */
    setupEventListeners() {
        // Menu item navigation
        document.querySelectorAll('.menu-item a').forEach(link => {
            link.addEventListener('click', (e) => this.handleMenuClick(e));
        });

        // Category button filtering
        document.querySelectorAll('.category-btn').forEach(btn => {
            btn.addEventListener('click', (e) => this.handleCategoryClick(e));
        });

        // Card hover effects
        document.querySelectorAll('.api-card').forEach(card => {
            card.addEventListener('mouseenter', () => this.cardHoverEnter(card));
            card.addEventListener('mouseleave', () => this.cardHoverLeave(card));
        });

        // Window frame focus effect
        document.querySelectorAll('.window-frame').forEach(frame => {
            frame.addEventListener('mouseenter', () => this.windowFocus(frame));
            frame.addEventListener('mouseleave', () => this.windowBlur(frame));
        });
    }

    /**
     * Handle menu item clicks
     */
    handleMenuClick(e) {
        e.preventDefault();
        
        // Update active state
        document.querySelectorAll('.menu-item').forEach(item => {
            item.classList.remove('active');
        });
        e.target.closest('.menu-item').classList.add('active');

        // Get the target section
        const targetId = e.target.getAttribute('href');
        const targetElement = document.querySelector(targetId);
        
        if (targetElement) {
            this.smoothScroll(targetElement);
            this.highlightElement(targetElement);
        }
    }

    /**
     * Handle category button clicks
     */
    handleCategoryClick(e) {
        // Update active state
        document.querySelectorAll('.category-btn').forEach(btn => {
            btn.classList.remove('active');
        });
        e.target.classList.add('active');

        // Filter cards based on category (demo functionality)
        const category = e.target.textContent.trim();
        this.filterCards(category);
    }

    /**
     * Filter cards by category
     */
    filterCards(category) {
        const cards = document.querySelectorAll('.api-card');
        
        cards.forEach(card => {
            const badge = card.querySelector('.badge');
            if (!badge || badge.textContent.toLowerCase() === category.toLowerCase() ||
                this.isCategoryMatch(badge, category)) {
                card.style.opacity = '1';
                card.style.pointerEvents = 'auto';
            } else {
                card.style.opacity = '0.5';
                card.style.pointerEvents = 'none';
            }
        });
    }

    /**
     * Check if category matches badge
     */
    isCategoryMatch(badge, category) {
        const badgeMap = {
            'Graphics': ['badge-graphics'],
            'Audio': ['badge-audio'],
            'Input': ['badge-input'],
            'Game Objects': ['badge-system', 'badge-ui'],
            'Scenes & Windows': ['badge-ui', 'badge-system'],
            'Utils': ['badge-system']
        };

        if (category === 'Graphics') {
            return !badge.className.match(/badge-(audio|input|ui)/);
        }
        
        return badgeMap[category]?.some(c => badge.classList.contains(c)) || category === 'Utils';
    }

    /**
     * Card hover enter effect
     */
    cardHoverEnter(card) {
        card.style.transform = 'translateY(-4px) scale(1.02)';
        card.style.boxShadow = '0 8px 24px rgba(74, 122, 170, 0.6), inset 0 0 2px rgba(74, 122, 170, 0.3)';
    }

    /**
     * Card hover leave effect
     */
    cardHoverLeave(card) {
        card.style.transform = 'translateY(-2px) scale(1)';
        card.style.boxShadow = '0 4px 16px rgba(74, 122, 170, 0.4), inset 0 0 1px rgba(74, 122, 170, 0.2)';
    }

    /**
     * Window frame focus effect
     */
    windowFocus(frame) {
        frame.style.boxShadow = `inset 1px 1px 0 rgba(255, 255, 255, 0.2),
                                  inset -1px -1px 0 rgba(0, 0, 0, 0.8),
                                  0 6px 20px rgba(202, 156, 109, 0.3)`;
    }

    /**
     * Window frame blur effect
     */
    windowBlur(frame) {
        frame.style.boxShadow = `inset 1px 1px 0 rgba(255, 255, 255, 0.15),
                                  inset -1px -1px 0 rgba(0, 0, 0, 0.6),
                                  0 4px 12px rgba(0, 0, 0, 0.7)`;
    }

    /**
     * Highlight element temporarily
     */
    highlightElement(element) {
        const originalBackground = element.style.background;
        element.style.background = 'linear-gradient(135deg, rgba(202, 156, 109, 0.2), rgba(106, 154, 204, 0.2))';
        element.style.transition = 'background 0.3s ease';
        
        setTimeout(() => {
            element.style.background = originalBackground;
        }, 2000);
    }

    /**
     * Setup smooth scroll
     */
    setupSmoothScroll() {
        document.querySelectorAll('a[href^="#"]').forEach(anchor => {
            anchor.addEventListener('click', (e) => {
                const href = anchor.getAttribute('href');
                if (href !== '#' && document.querySelector(href)) {
                    e.preventDefault();
                    this.smoothScroll(document.querySelector(href));
                }
            });
        });
    }

    /**
     * Smooth scroll to element
     */
    smoothScroll(element) {
        const container = document.querySelector('.rpg-content');
        const targetPosition = element.offsetTop - 20;
        const startPosition = container.scrollTop;
        const distance = targetPosition - startPosition;
        const duration = 600;
        let start = null;

        const ease = (t) => {
            return t < 0.5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
        };

        const animation = (currentTime) => {
            if (start === null) start = currentTime;
            const elapsed = currentTime - start;
            const progress = Math.min(elapsed / duration, 1);
            
            container.scrollTop = startPosition + distance * ease(progress);
            
            if (progress < 1) {
                requestAnimationFrame(animation);
            }
        };

        requestAnimationFrame(animation);
    }

    /**
     * Load initial application state
     */
    loadInitialState() {
        // Log available classes (simulated)
        console.log('%c LunaLite API GUI Loaded', 'color: #c69c6d; font-size: 16px; font-weight: bold;');
        console.log('%c RPG Maker MZ & MV Documentation', 'color: #6a9acc; font-size: 12px;');
        
        // Add keyboard shortcuts
        this.setupKeyboardShortcuts();
        
        // Load statistics
        this.updateStatistics();
    }

    /**
     * Setup keyboard shortcuts
     */
    setupKeyboardShortcuts() {
        document.addEventListener('keydown', (e) => {
            // Ctrl/Cmd + K for search (can be implemented)
            if ((e.ctrlKey || e.metaKey) && e.key === 'k') {
                e.preventDefault();
                this.openSearch();
            }
            
            // Escape to close search
            if (e.key === 'Escape') {
                this.closeSearch();
            }
        });
    }

    /**
     * Open search functionality (placeholder)
     */
    openSearch() {
        console.log('Search functionality - to be implemented');
        // Could open a search modal or highlight search input
    }

    /**
     * Close search functionality (placeholder)
     */
    closeSearch() {
        console.log('Search closed');
    }

    /**
     * Update statistics display
     */
    updateStatistics() {
        // Simulated statistics - in a real application, these would come from the API
        const stats = {
            totalClasses: 50,
            totalMethods: 500,
            version: '1.0.0'
        };

        // Could update the status bar with real data
        console.log('Statistics loaded:', stats);
    }

    /**
     * Search for API items
     */
    searchAPI(query) {
        const items = document.querySelectorAll('.api-card');
        const results = [];

        items.forEach(item => {
            const header = item.querySelector('.card-header').textContent.toLowerCase();
            const body = item.querySelector('.card-body').textContent.toLowerCase();

            if (header.includes(query.toLowerCase()) || body.includes(query.toLowerCase())) {
                results.push(item);
            }
        });

        return results;
    }

    /**
     * Highlight search results
     */
    highlightSearchResults(results) {
        document.querySelectorAll('.api-card').forEach(card => {
            card.style.opacity = '0.3';
        });

        results.forEach(result => {
            result.style.opacity = '1';
            result.style.border = '2px solid #c69c6d';
        });
    }

    /**
     * Clear search highlighting
     */
    clearSearchHighlight() {
        document.querySelectorAll('.api-card').forEach(card => {
            card.style.opacity = '1';
            card.style.border = '2px solid #606098';
        });
    }

    /**
     * Export API reference to JSON
     */
    exportToJSON() {
        const cards = document.querySelectorAll('.api-card');
        const data = [];

        cards.forEach(card => {
            data.push({
                name: card.querySelector('.card-header').textContent,
                description: card.querySelector('.card-body p').textContent,
                type: card.querySelector('.badge').textContent
            });
        });

        return JSON.stringify(data, null, 2);
    }

    /**
     * Print-friendly view
     */
    printView() {
        window.print();
    }
}

// Initialize the GUI when DOM is ready
document.addEventListener('DOMContentLoaded', () => {
    window.lunaGUI = new LunaLiteAPIGUI();
    
    // Make globally available methods
    window.searchAPI = (query) => window.lunaGUI.searchAPI(query);
    window.exportAPI = () => window.lunaGUI.exportToJSON();
    window.printView = () => window.lunaGUI.printView();
});
